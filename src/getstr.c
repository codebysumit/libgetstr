/**
 * GETSTR Library for C
 * https://github.com/codebysumit/libgetstr/
 *
 * Copyright (c) 2025 SUMIT DAS
 * All rights reserved
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#define _GNU_SOURCE    // For potentially useful GNU extensions, though not strictly required for this implementation

#include "getstr.h"    // Our custom header
#include <stdio.h>     // For fgetc, vprintf, ungetc
#include <stdlib.h>    // For malloc, realloc, free
#include <string.h>    // For strlen, etc.
#include <errno.h>     // For errno
#include <stdbool.h>   // For true and false boolian value keyword
#include <stdint.h>    // For SIZE_MAX

// Implement the getstrf function
str getstrf(const char *format, ...)
{
    // --- Display the Prompt ---
    if (format != NULL)
    {
        va_list args;
        va_start(args, format);
        vprintf(format, args); // Print the formatted prompt
        va_end(args);
    }

    // --- Read User Input ---
    size_t capacity = 128; // Initial buffer capacity
    str buffer = (str)malloc(capacity);
    if (buffer == NULL)
    {
        perror("Failed to allocate initial buffer for input");
        return NULL; // Memory allocation failed
    }

    size_t length = 0; // Current length of the string in the buffer
    int c;             // Character read from stdin

    while (true)
    {
        c = fgetc(stdin); // Read one character

        if (c == EOF || c == '\n')
        {
            // End of input or newline found
            break;
        }

        // If buffer is full, reallocate to a larger size
        if (length + 1 >= capacity) // +1 for the current character
        {
            // Check for potential overflow before doubling
            if (capacity > SIZE_MAX / 2) {
                // Cannot double without overflowing size_t, try to increment by a smaller amount or error
                // For simplicity, we'll return NULL here, but more robust error handling could be added.
                free(buffer);
                return NULL;
            }
            capacity *= 2; // Double the capacity
            str temp = (str)realloc(buffer, capacity);
            if (temp == NULL)
            {
                perror("Failed to reallocate buffer for input");
                free(buffer); // Free the original buffer before returning NULL
                return NULL;
            }
            buffer = temp;
        }

        buffer[length++] = (char)c; // Add character to buffer and increment length
    }

    // --- Handle CRLF for Windows compatibility (optional, but good practice) ---
    // If the last character was \r and we read it before \n,
    // and the next character is \n, consume it.
    // This simple implementation already handles \r and \n as terminators.
    // For a more exact replica that handles `\r` then `\n` without `\r` being part of string:
    // If we read '\r' as the line terminator, and the next char is '\n', consume it.
    // However, our current loop terminates on '\r' or '\n', so it's simpler:
    // If `c` was '\r' and `fgetc(stdin)` returns `\n`, then `\n` is discarded.
    if (c == '\r') {
        int next_c = fgetc(stdin);
        if (next_c != '\n' && next_c != EOF) {
            ungetc(next_c, stdin); // Push back if it's not '\n' or EOF
        }
    }

    // --- Finalize the String ---
    if (length == 0 && c == EOF)
    {
        // No input and EOF reached immediately (e.g., Ctrl+D at start)
        free(buffer);
        return NULL;
    }

    // Reallocate to the exact size needed + 1 for null terminator
    str final_string = (str)realloc(buffer, length + 1);
    if (final_string == NULL)
    {
        perror("Failed to reallocate final string buffer");
        free(buffer); // In case realloc failed but buffer still points to old memory
        return NULL;
    }

    final_string[length] = '\0'; // Null-terminate the string

    // Return an empty string if user just pressed Enter
    if (length == 0) {
        // realloc for length + 1 (which is 1) will create a single-byte string
        // containing just '\0', which is an empty string.
        // We can just return final_string in this case.
    }

    return final_string;
}
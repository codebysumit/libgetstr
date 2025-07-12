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

#ifndef GETSTR_H
#define GETSTR_H

#include <stdarg.h> // Required for va_list
#include <stddef.h> // Required for size_t

// Our own type for (pointers to) strings
typedef char *str;

/**
 * @brief Prompts the user for a line of text from standard input and returns
 * it as a dynamically allocated string (char *).
 *
 * This function can take a format
 * string and variable arguments, just like printf, to display a prompt to the user.
 * It reads the entire line of input until a newline character or EOF.
 * The returned string is dynamically allocated on the heap and should be freed
 * by the caller when no longer needed to prevent memory leaks.
 *
 * @param format A printf-style format string for the prompt.
 * @param ... Variable arguments for the format string.
 * @return A dynamically allocated string containing the user's input,
 * or NULL if an error occurs (e.g., memory allocation failure, EOF).
 * An empty string "" is returned if the user just presses Enter.
 */

// https://www.ibm.com/docs/en/xl-c-and-cpp-aix/16.1.0?topic=attributes-format

str getstrf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif // GETSTR_H

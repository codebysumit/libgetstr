## GETSTR - A User-Friendly C String Input Library
#### Overview 🚀
The getstr library provides a simple yet robust set of functions for acquiring string input from the user in C programming. Designed to be more user-friendly than standard C input functions, `getstr` offers a dynamic `getstrf()` function that supports printf-like formatting for prompts and automatically handles dynamic memory allocation for user input.
#### Features ✨
 * **Formatted Prompts:** Display prompts to the user using familiar printf-style format strings.
 * **Dynamic Input Buffer:** Automatically expands the input buffer to accommodate strings of any length, preventing buffer overflows.
 * **Cross-Platform Line Ending Handling:** Gracefully handles common line endings (`\n`, `\r\n`).
 * **Robust Error Handling:** Returns NULL on memory allocation failures or immediate End-Of-File (EOF).
 * **Simplified String Type:** Introduces a `str` type alias for `char *` for enhanced readability.

### Installation 🛠️
To use the `getstr` library in your C projects, follow these steps to compile it into a static library (`.a` file) and link it with your applications.

**1. Download the Library Files 📥**

Download the latest version of the `getstr` library header (`getstr.h`) and source (`getstr.c`) files from the official GitHub repository: [GITHUB/LIBGETSTR](https://github.com/codebysumit/libgetstr/tree/master/src) 

Make sure both `getstr.h` and `getstr.c` are placed in the same directory.

**2. Compile the Source Code ⚙️**

Navigate to the directory where you saved `getstr.c` and `getstr.h` in your terminal or command prompt. Compile the `getstr.c` file using GCC (or your preferred C compiler):

```bash
gcc -c getstr.c
```

This command creates a compiled object file named `getstr.o` in the same directory.

**3. Create the Static Library 📦**

Use the `ar` (GNU Binutils) tool to create an archive static library file. On Windows, MinGW compilers typically have `ar` installed by default.

```bash
ar rcs libgetstr.a getstr.o
```

This command creates a static library file named `libgetstr.a`.

Note: You can now delete the `getstr.o` file as it's no longer needed after creating the static library.

**4. Organize File Structure (Optional but Recommended) 🗂️**

For better project organization, you can create a specific directory structure to manage your library files:

```bash
.
├── include/
│   └── getstr.h
├── lib/
│   └── libgetstr.a
└── your_application.c
```

Copy the `getstr.h` header file to the `include` directory. Move the static library `libgetstr.a` to the `lib` directory.

**5. Compile Your Application with the Library 💻**

When compiling your application (`your_application.c` in the example above) that uses `getstr`, you need to tell the compiler where to find the header files and the library file.

```bash
gcc -I./include -L./lib your_application.c -o your_application -lgetstr
```
**Explanation of flags:**
 * **`-I./include`:** Specifies the directory containing the header files (here, `./include`).
 * **`-L./lib`:** Specifies the directory containing the libraries (here, `./lib`).
 * **`your_application.c`:** The source code file of your application.
 * **`-o your_application`:** Sets the output executable file name to `your_application`.
 * **`-lgetstr`:** Links the program with the static library `libgetstr.a` (the `-l` flag expects the library name without the `lib` prefix and `.a` suffix).

### Usage 💡
Once installed, you can include `getstr.h` in your C source files and use the `getstrf()` function.

**Example:**

Here's a simple example demonstrating how to use `getstrf()`:

Link with `-lgetstr`.

```c
#include <getstr.h>
#include <stdio.h>


int main()
{
    str string = getstrf("Prompt: ");
    printf("Output string: %s!\n", string);
    return 0;
}
```

**Running the Example**

After compiling the example (e.g., as test using the installation steps), run it from your terminal:

```bash
gcc -I./include -L./lib test.c -o test -lgetstr
```

```bash
./test
```

**Example Output:**

```bash
Prompt: This is a String.
Output string: This is a String.
```

### Memory Management 💾

The `getstrf()` function dynamically allocates memory on the heap to store the user's input. It is crucial that you `free()` this memory using `free()` from `stdlib.h` once you are finished with the string to prevent memory leaks.

**Example:**
```c
#include <getstr.h>    // For str keyword and getstrf()
#include <stdio.h>     // For printf()
#include <stdlib.h>    // For free()


int main()
{
	str string = getstrf("Prompt: ");
	printf("Before using free(): %s\n", string);
	free(string);
	printf("After using free(): %s\n", string);
	return 0;
}
```

### Reference 📚

For a visual guide on compiling and linking C libraries, you can refer to this YouTube video tutorial: [Elatronion](https://youtu.be/m6RVY84_mQE)

### License 📜

This project is licensed under the MIT License - see the LICENSE section above for details.

### Contributing 🤝

Contributions are welcome! If you find bugs, have suggestions for improvements, or would like to contribute new features, please open an issue or submit a pull request on the GitHub repository.

### Contact 📬

For any questions or feedback, please reach out to the project maintainer:
 * Project Maintainer 👨‍💻: Sumit Das
 * Email ✉️: [codebysumit@gmail.com](mailto:codebysumit@gmail.com)

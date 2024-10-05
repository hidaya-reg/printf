# 0x11. C - printf
### Concepts
<details>
<summary>Printf function brief - What to know to create your own Printf function</summary>

### 1. Introduction to ``printf``
#### Overview of ``printf``:
The ``printf`` function in C is used for formatted output. It’s part of the Standard Input/Output Library (``stdio.h``) and is responsible for printing data to the standard output (typically the console) in a specified format. 

#### The Format String:
At the core of ``printf`` is the format string. This string contains both text and format specifiers, which are placeholders for the values you want to print. Format specifiers start with a ‘%’ character, followed by a character that indicates the type of data to be printed (e.g., ``%d`` for integers, ``%s`` for strings).

Here’s a simple example:
```c
int age = 30;
printf("I am %d years old.", age);
```
In this example, ``"I am %d years old."`` is the format string, and ``%d`` is the format specifier. The ``%d`` specifier tells ``printf`` to expect an integer value, which is provided as ``age``.

The ``printf`` function processes the format string, replacing format specifiers with the actual values you provide as arguments.

### 2. Argument Handling
#### Handling Variable Numbers of Arguments:
One of the unique features of ``printf`` is its ability to accept a variable number of arguments. This is accomplished using variadic functions in C. The ``printf`` function, like many other standard C library functions, is declared with the ``stdarg.h`` header to enable this functionality.

Here’s a simplified explanation of how it works:

1. ``printf`` first encounters the format string and parses it to identify format specifiers (e.g., ``%d``, ``%s``).

2. For each format specifier, ``printf`` expects an argument of the corresponding type. For ``%d``, it expects an ``int``, for ``%s``, it expects a ``char*``, and so on.

3. The number of format specifiers determines the number of arguments ``printf`` needs to process.

4. You pass these arguments to ``printf`` after the format string.

#### Variadic Functions:
To handle this variable number of arguments, ``printf`` uses the ``stdarg.h`` library, which provides macros like ``va_list``, ``va_start``, and ``va_arg``. These macros allow ``printf`` to access its arguments sequentially, even though it doesn’t know the number or types of arguments at compile-time.

### 3. Processing Format Specifiers
#### Understanding Format Specifiers:
Format specifiers in printf are placeholders that tell the function how to format and print data. They start with a ‘%’ character and are followed by a character that specifies the data type to be printed.

Here are some common format specifiers:

| Format Specifier | Description                                    |
|------------------|------------------------------------------------|
| `%d`             | Format as a signed decimal integer.            |
| `%u`             | Format as an unsigned decimal integer.         |
| `%f`             | Format as a floating-point number.             |
| `%s`             | Format as a null-terminated string.            |
| `%c`             | Format as a character.                         |
| `%x`             | Format as a hexadecimal number, lowercase.     |
| `%X`             | Format as a hexadecimal number, uppercase.     |


#### Handling Flags, Field Width, Precision, and Length Modifiers:
``printf`` format specifiers can also include optional modifiers. These modifiers control the output format further. Some common modifiers include:

| Feature          | Description                                                                                  |
|------------------|----------------------------------------------------------------------------------------------|
| Flags            | Control the alignment and representation of the output (e.g., `%-10d` for left-justified integer). |
| Field Width      | Specify the minimum width of the output field (e.g., `%5d` for a minimum width of 5 characters). |
| Precision        | Control the number of decimal places for floating-point numbers (e.g., `%.2f` for two decimal places). |
| Length Modifiers | Specify the size of the argument (e.g., `%ld` for a long integer).                           |

### 4. Converting and Formatting
#### Role of Type Conversion:
Once ``printf`` identifies the expected data type from the format specifier, it performs type conversion on the argument to match that data type. This ensures that the data is appropriately formatted for printing. For example, if ``%d`` is encountered, ``printf`` expects an ``int``, and if the argument is a ``double``, it will be converted to an ``int``.

#### Formatting Data for Output:
The way data is printed depends on the format specifier. For instance:

- ``%d`` formats an integer as a signed decimal.
- ``%f`` formats a floating-point number as a decimal.
- ``%s`` prints a null-terminated string.
- ``%c`` prints a single character.

Each format specifier has its own rules for formatting and printing data, including how many characters to print, whether to add leading zeros, and how to handle precision for floating-point numbers.
For example:
```c
double pi = 3.14159265;
printf("Value of pi: %.2f", pi);
```
In this case, ``%.2f`` specifies that the ``pi`` variable should be formatted as a floating-point number with two decimal places.

#### Handling Different Data Types:
``printf`` is versatile and can handle various data types like integers, characters, strings, floats, etc., by using the appropriate format specifiers.

### 5. Output Generation
#### How `printf` Generates Formatted Output:
After processing the format string, matching format specifiers with arguments, and converting and formatting the data, `printf` needs to generate the final formatted output.

Here’s a simplified overview of this process:

1. ``printf`` internally builds a string to represent the final formatted output. This string is often referred to as a “buffer.”

2. For each part of the format string that is not a format specifier (i.e., regular text), ``printf`` copies it directly into the buffer.

3. When printf encounters a format specifier, it converts the corresponding argument to a string representation based on the specifier and appends it to the buffer.

4. The buffer accumulates these pieces as it processes the format string.

5. Finally, when all format specifiers and text parts have been processed, ``printf`` writes the contents of the buffer to the standard output (typically the console).

#### Buffering and Writing to Standard Output:
Buffering is an important concept in output functions like ``printf``. It allows the program to build up the output in memory and write it to the standard output in more efficient chunks, reducing the number of actual write operations. This is done to improve performance.

``printf`` might not write to the standard output immediately after processing each format specifier. Instead, it often waits until the buffer is filled or until a newline character (``'\n'``) is encountered. However, you can force flushing the buffer (writing its content to the output) using ``fflush(stdout)`` or when a newline character is encountered in the format string.

### 6. Error Handling
#### Dealing with Format String Errors:
``printf`` is designed to handle various format specifiers and format string combinations. However, it’s essential to understand how it deals with format string errors, such as mismatched format specifiers and arguments.

- If ``printf`` encounters a format specifier that doesn’t match the provided arguments, it can lead to undefined behavior. This is one area where you’ll need to be cautious when designing your custom version.
- Some compilers and libraries may provide warnings or errors for format string mismatches, but it’s not guaranteed.
#### Handling Argument Mismatches:
``printf`` expects arguments to match the format specifiers in the order they appear in the format string. If arguments are missing or provided in the wrong order, it can lead to errors or unexpected behavior.
For example:
``` c
int num = 42;
printf("Value: %s", num); // This will produce undefined behavior.
```
In this case, the format specifier ``%s`` expects a string argument, but ``num`` is an integer. This can lead to unpredictable results.

### 7. Modifiers and Special Cases
#### Handling Special Format Specifiers:
``printf`` supports special format specifiers, such as ``%%`` and ``%n``:

- ``%%``: This format specifier is used to print a literal ’%‘ character. For example, ``printf("This is a percent sign: %%");`` will print “This is a percent sign: %”.
- ``%n``: ``%n`` doesn’t actually print anything; instead, it stores the number of characters printed so far into an ``int*`` argument. This can be useful for tracking the number of characters printed.
For example:
```c
int count;
printf("Count: %d%n", 42, &count);
```
In this example, ``%n`` is used to store the number of characters printed in the count variable.

### 8. Memory Management
#### Memory Allocation in Custom ``printf``:
Depending on your custom ``printf`` implementation, you might need to allocate memory dynamically, especially when dealing with format specifiers like ``%s`` that expect string arguments of varying lengths.

Here are some key points to consider:

- When ``printf`` encounters a ``%s`` specifier, it expects a pointer to a null-terminated string. If you’re going to support ``%s``, you’ll need to allocate memory for the string and handle its lifecycle (e.g., freeing the memory when it’s no longer needed).

- Be mindful of memory leaks. If your custom ``printf`` allocates memory dynamically, ensure that you release this memory appropriately to avoid memory leaks.

- Think about memory allocation strategies that suit your specific use cases. You might use ``malloc`` and ``free`` for dynamic memory allocation and deallocation.

- Consider buffer overflows. Make sure your custom ``printf`` doesn’t write more data to an allocated buffer than it can hold to prevent buffer overflows.

### 9. Testing and Debugging
#### Strategies for Testing Your Custom ``printf``:
Testing your custom ``printf`` implementation is crucial to ensure it works correctly and reliably. Here are some strategies you can use:

**1. Unit Testing:** Break down your custom ``printf`` into smaller functions or components, and test each one individually. This makes it easier to isolate and fix issues.

**2. Test Cases:** Create a variety of test cases that cover different format specifiers, data types, modifiers, and edge cases. Include cases where format specifiers and arguments mismatch to test error handling.

**3. Comparison with Standard ``printf``:** Use the standard ``printf`` function as a reference. Compare the output of your custom implementation with the output of the standard ``printf`` to ensure they match for the same input.

**4. Memory Testing:** If your custom printf allocates memory dynamically, perform memory leak detection using tools like Valgrind or AddressSanitizer.

**5. Corner Cases:** Test your custom ``printf`` with extreme or unusual cases, such as very large numbers or unusual format specifiers.

#### Debugging Common Issues:
Here are some common issues you might encounter when building your custom ``printf``:

- **Format String Parsing:** Ensure that you parse the format string correctly to identify format specifiers and text segments accurately.

- **Argument Handling:** Check that your custom ``printf`` correctly handles different data types, conversions, and modifiers.

- **Buffer Management:** If you’re using a buffer for output, make sure it’s correctly managed to prevent overflows and underflows.

- **Memory Management:** If you allocate memory dynamically, pay close attention to memory leaks and ensure proper deallocation.

- **Error Handling:** Verify that your custom ``printf`` handles format string errors and argument mismatches appropriately without causing undefined behavior.

- **Performance:** Profile your custom ``printf`` to identify performance bottlenecks and optimize if necessary.

### 10. Optimization and Efficiency
#### Strategies for Optimizing Your Custom ``printf``:
While building your custom ``printf``, optimizing its performance and efficiency can be important, especially if it’s going to be used extensively in your codebase. Here are some optimization strategies to consider:

**1. Minimize Memory Allocation:** If your custom ``printf`` allocates memory dynamically, aim to minimize these allocations. Reuse buffers where possible to reduce memory overhead.

**2. Buffering:** Implement efficient buffering mechanisms to reduce the number of write operations to the standard output. Writing to the output in larger chunks is generally faster than writing one character at a time.

**3. Avoid Redundant Conversions:** Try to avoid redundant type conversions. If you’ve already converted a value to a string, reuse that string instead of converting it again if it’s used multiple times in the same format string.

**4. Use Efficient Data Structures:** Choose appropriate data structures for intermediate storage. For example, use a StringBuilder-like structure for building the output string.

**5. Compiler Optimization Flags:** Utilize compiler optimization flags (e.g., ``-O2`` or ``-O3`` for GCC) to let the compiler optimize your code for performance.

**6. Avoid Excessive String Concatenation:** String concatenation can be expensive in terms of both memory and time. Minimize the number of string concatenation operations.

**7. Profiling:** Use profiling tools to identify performance bottlenecks in your code and focus optimization efforts where they will have the most impact.

**8. Caching:** If your custom ``printf`` is used with repeated identical format strings, consider caching the formatted output to avoid redundant processing.

Optimization should always be done with a clear understanding of the trade-offs involved. Sometimes, code readability and maintainability should take precedence over optimization efforts.

Remember that premature optimization can lead to complex and error-prone code. Start with clear, well-structured code, and then optimize the bottlenecks when you have evidence that they are causing performance issues.
</details>

### Resources

[Secrets of printf](https://www.academia.edu/10297206/Secrets_of_printf_)

### Compilation
- Your code will be compiled this way:
``$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c``
- As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)
- Our main files will include your main header file (main.h): #include main.h
- You might want to look at the gcc flag -Wno-format when testing with your _printf and the standard printf. Example of test file that you could use:
```bash
$ cat main.c 
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
```
## Tasks
### 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to a format.

**Prototype:** ``int _printf(const char *format, ...);``
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- ``format`` is a character string. The format string is composed of zero or more directives. You need to handle the following conversion specifiers:
    + ``c``
    + ``s``
    + ``%``
- You don’t have to reproduce the buffer handling of the C library ``printf`` function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers
  
### 1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
- ``d``
- ``i``
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers
  
### 2. With a face like mine, I do better in print
Handle the following custom conversion specifiers:

``b``: the unsigned int argument is converted to binary
```bash
$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
$ ./a.out
1100010
```
### 3. What one has not experienced, one will never understand in print
Handle the following conversion specifiers:
- ``u``
- `o`
- `x`
- `X`
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

### 4. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call ``write`` as little as possible.

### 5. My weakness is wearing too much leopard print
Handle the following custom conversion specifier:
- `S` : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
```bash
$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
$ ./a.out
Best\x0ASchool
```
### 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
Handle the following conversion specifier: `p`

- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

### 7. The big print gives and the small print takes away
Handle the following flag characters for non-custom conversion specifiers:

- `+`
- space
- `#`
  
### 8. Sarcasm is lost in print
Handle the following length modifiers for non-custom conversion specifiers:
- `l`
- `h`

Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`

### 9. Print some money and give it to us for the rain forests
Handle the field width for non-custom conversion specifiers.
  
### 10. The negative is the equivalent of the composer's score, and the print the performance
Handle the precision for non-custom conversion specifiers.
  
### 11. It's depressing when you're still around and your albums are out of print
Handle the `0` flag character for non-custom conversion specifiers.
  
### 12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection
Handle the - flag character for non-custom conversion specifiers.
  
### 13. Print is the sharpest and the strongest weapon of our party
Handle the following custom conversion specifier:

`r` : prints the reversed string

### 14. The flood of print has turned reading into a process of gulping rather than savoring
Handle the following custom conversion specifier:

`R`: prints the rot13'ed string

### 15. *
All the above options work well together.

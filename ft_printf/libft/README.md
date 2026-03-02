*This project has been created as part of the 42 curriculum by ialrandr.*

# LIBFT

## Description

Libft is a custom C library that recreates essential functions from the C standard library, along with additional utility functions for string manipulation, memory management, and linked list operations. This project serves as a foundation for future 42 projects, teaching low-level programming concepts and helping build a deeper understanding of how standard library functions work under the hood.

The library includes three categories of functions:
- **Part 1**: Standard C library functions (libc) such as `memcpy`, `strlen`, `atoi`, etc.
- **Part 2**: Additional utility functions for string operations like `ft_substr`, `ft_split`, `ft_itoa`, etc.
- **Part 3**: Linked list manipulation functions for creating and managing `t_list` structures.

## Library Details

`libft` is designed as a reusable static library that reimplements a subset of functions from the C standard library while also providing additional utility functions frequently required in C projects. All functions are declared in a single public header file `libft.h` and follow a consistent naming convention using the `ft_` prefix.

This library is divided into several logical groups:
- **Character checks and conversions** - Functions like `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`
- **Memory allocation and operations** - Functions like `ft_memset`, `ft_memcpy`, `ft_calloc`, `ft_bzero`
- **String manipulation and parsing** - Functions like `ft_strlen`, `ft_strjoin`, `ft_split`, `ft_substr`
- **File descriptor operations (output)** - Functions like `ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`
- **Linked list manipulation** - Functions like `ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`, `ft_lstclear`

All functions adhere to strict coding standards and handle edge cases such as NULL pointers and malloc failures to prevent segmentation faults and undefined behavior.

## Instructions

### Compilation

To compile the library (includes all functions):
```bash
    make
    # or
    make all
```
This generates `libft.a` and displays "Build Successfull" when complete.

To recompile from scratch:
```bash
make re
```
To remove object files:
```bash
make clean
```
To remove all generated files (objects and library):
```bash
make fclean
```
**Compilation flags used:** `-Wall -Wextra -Werror`

### Usage

Include the header in your C files:
```c
#include "libft.h"
```
Compile your program with the library:
```bash
cc your_file.c libft.a -o your_program
```
Or using the `-L` and `-l` flags:
```bash
cc your_file.c -L. -lft -o your_program
```
## Resources

### Documentation & Tutorials
- **Man Pages** - Use `man <function>` in terminal (e.g., `man memcpy`, `man strlen`) for official C function documentation
- [TutorialsPoint - C Programming](https://www.tutorialspoint.com/cprogramming/index.htm) - Comprehensive C programming reference for understanding standard library functions and C language fundamentals

### AI Usage
AI tools (GitHub Copilot) were used in this project for:
- **Testing**: Generating test cases and validating function implementations against edge cases
- **Explanations**: Understanding complex memory management concepts and debugging segmentation faults
- **Code Review**: Identifying potential issues with malloc failure handling and norminette compliance

All core implementations were written manually following 42 school guidelines.

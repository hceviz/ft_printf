# ft_printf

## Project Overview
Reimplementation of the C standard printf function with limited conversion specifiers, focusing on formatted output and low-level memory handling.

## Description
The ft_printf project is a 42 School assignment aimed at recreating the functionality of the C standard printf function. It outputs formatted data to the standard output, handling a subset of format specifiers.

## Supported Conversions
The function handles the following conversion specifiers:
- %c — character
- %s — string
- %p — pointer address
- %d — decimal integer
- %i — integer
- %u — unsigned decimal
- %x — lowercase hexadecimal
- %X — uppercase hexadecimal
- %% — literal percent sign

## Compilation
```bash
make
```
## Usage
```c
#include "ft_printf.h"
int main(void)
{
    int len = ft_printf("Hello %s!\n", "world");
    ft_printf("Printed %d characters.\n", len);
    return 0;
}
```
## Constraints
- No use of standard printf or related functions
- Used only allowed libc functions (write, malloc, free)
- Manages memory safely (no leaks or undefined behavior)

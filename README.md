# ft_printf
The goal of this project is pretty straightforward. You will recode printf().
You will mainly learn about using a variable number of arguments. How cool is that??
It is actually pretty cool :)

## Introduction
For this project of the 42 school cursus, we must recreate the famous C library printf function. This project teaches us about variadic arguments as well as structures if we plan to implement printf's extra flags.

- Supported conversions: %, c, s, p, i, d, u, x, X
- Supported flags: # + (space)
- Supported options: - 0 . width

## Status
Finished: 2024-02-04. Grade: 125/100.

## Usage

``make`` to compile libftprintf.a, a library that contains ft_printf functions and it's dependencies (including Libft).

### Basic Usage
For example, let's create a ``main.c`` file.

```c
// Include the header
#include "ft_printf.h"

int main(void)
{
      // Call the function
      ft_printf("Testing ft_printf!");
      return (0);
}
```

Compile the ``main.c`` file with the ft_printf library and run the program:
```bash
gcc main.c libftprintf.a && ./a.out
```
Output should be:
```
Testing ft_printf!
```

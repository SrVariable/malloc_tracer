# Malloc Tracer

A simple C library that allows to trace every malloc you use.

# Available functions

what you will probably need is:

- ft\_malloc(size\_t size): Use it as a normal malloc
- ft\_free(void \*ptr): Use it as a normal free
- ft\_cleanup(void): Use it to free every pointer allocated by ft\_malloc

For more information, check the source code.

# Usage

Clone the repository

```shell
git clone https://github.com/SrVariable/malloc_tracer.git
cd malloc_tracer
```

Generate the static library (.a file)

```shell
make
```

Simple program

```c
#include "malloc_tracer.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    const char *msg = "Hello world!";
    char *s = ft_malloc(strlen("Hello world!") + 1);
    strcpy(s, msg);
    printf("%s\n", s);
    ft_free(s); // You could also ft_cleanup()
    return (0);
}
```

Compile the program

```shell
gcc -o program program.c libmalloctracer.a
./program
```

It should output

```plaintext
Hello world!
```

There's also a `main.c` that contains a simple program.

You can run it with

```shell
make example
```

Or with

```
make example_debug
```

# Leaks

To check that there isn't any leaks, you can use tools like [Valgrind](https://valgrind.org/) or using the flag -fsanitize=address

## Valgrind

Regenerate the static library with debug information

```shell
make debug
```

Compile the program with debug flag

```shell
gcc -o program -g program.c libmalloctracer.a
```

Execute Valgrind

```shell
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./program
```

It should output something similar to this

```plaintext
==64097== Memcheck, a memory error detector
==64097== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==64097== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==64097== Command: ./program
==64097==
Hello world!
==64097==
==64097== HEAP SUMMARY:
==64097==     in use at exit: 0 bytes in 0 blocks
==64097==   total heap usage: 3 allocs, 3 frees, 1,061 bytes allocated
==64097==
==64097== All heap blocks were freed -- no leaks are possible
==64097==
==64097== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Fsanitize

Regenerate the static library with debug information

```shell
make debug
```

Compile the program with debug flag

```shell
gcc -o program -g -fsanitize=address program.c libmalloctracer.a
```

Execute the program

```shell
./program
```

It should output

```plaintext
Hello world!
```

# Contributing

If you find any problem, feel free to [open an issue](https://github.com/SrVariable/malloc_tracer/issues).
You can also fork the repository and send a Pull Request!.

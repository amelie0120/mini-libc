# Mini-libc

## Objectives

- Learn about the structure and functionalities provided by the standard C library
- Accommodate with the syscall interface in Linux
- Gain a better understanding of strings and memory management functions
- Learn how the standard C library provides support for low-level input/output operations

## Statement

**Minimalistic** [**standard C library**](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems (named **mini-libc**), that can be used as a replacement for the **system libc** ([glibc](https://www.gnu.org/software/libc/) in Linux).
It is is a minimally functional libc with features such as string management, basic memory support and POSIX file I/O.

The implementation of mini-libc is **freestanding**, i.e. it does not use any outside library calls.
It is implemented on top of the system call interface provided by Linux on an `x86_64` architecture.


### API and Implementation Tasks

The application programming interface (API) of the C standard library is declared in a number of header files.
Each header file contains one or more function declarations, data type definitions and macros.
For your minimal implementation, the following header files are of interest:

- `<string.h>`: defines string-handling functions

  Implemented functions: `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`, `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`, `memcpy()`, `memset()`, `memmove()`, `memcmp()`.

- `<stdio.h>`: defines printing and I/O functions

  Implemented functions: `puts()`.

- `<unistd.h>`, `<sys/fcntl.h>` and `<sys/stat.h>`: define I/O primitives

  Implemented functions: `open()`, `close()`, `lseek()`, `stat()`, `fstat()`, `truncate()`, `ftruncate()`, `nanosleep()` and `sleep()`.

- `<stdlib.h`> and `<sys/mman.h>` define memory allocation functions

  `nanosleep()` and `sleep()`: `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`, `mmap()`, `mremap()`, `munmap()`.

- `<errno.h>` and `errno.c`: declare and define the integer variable `errno`, which is set by system calls and some library functions in the event of an error to indicate what went wrong.


## Resources

- [GNU libc manual](https://www.gnu.org/software/libc/manual/html_mono/libc.html)

- [musl implementation of the standard C library for Linux-based systems](https://elixir.bootlin.com/musl/latest/source)

- Syscall interface in Linux - [Linux man pages online](https://man7.org/linux/man-pages/index.html)

- [glibc implementation of the standard C library for Linux-based systems](https://elixir.bootlin.com/glibc/latest/source)

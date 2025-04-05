# Mini-libc

## Overview

I developed a minimalistic implementation of the standard C library for Linux systems (mini-libc) that can be used as a replacement for the system libc (glibc in Linux). This project helped me:

- Deeply understand the structure and functionalities provided by the standard C library
- Master the syscall interface in Linux
- Develop a thorough understanding of strings and memory management functions
- Implement low-level input/output operations directly on top of system calls

The resulting library is completely freestanding (using no outside library calls) and is implemented directly on top of the Linux syscall interface for x86_64 architecture.

## Features Implemented

### String Handling (`<string.h>`)

I implemented core string manipulation functions including:
- `strcpy()` and `strncpy()` for string copying
- `strcat()` and `strncat()` for string concatenation
- `strlen()` for string length calculation
- `strcmp()` and `strncmp()` for string comparison
- `strstr()` and `strrstr()` for substring finding
- `memcpy()`, `memset()`, `memmove()`, and `memcmp()` for memory operations

Each function was carefully implemented to match standard behavior while handling edge cases correctly.

### Standard I/O (`<stdio.h>`)

I implemented basic output functionality:
- `puts()` for writing strings to stdout

### POSIX I/O Operations

I created low-level file operations by implementing:
- `open()` and `close()` for file handling
- `lseek()` for file positioning
- `stat()` and `fstat()` for retrieving file information
- `truncate()` and `ftruncate()` for file resizing
- `nanosleep()` and `sleep()` for process suspension

All functions handle errors properly and set the errno variable as expected.

### Memory Management

I built a complete memory allocation system including:
- `malloc()` for dynamic memory allocation
- `free()` for releasing allocated memory
- `calloc()` for allocated zeroed memory
- `realloc()` and `realloc_array()` for resizing allocations
- `mmap()`, `mremap()`, and `munmap()` for memory mapping operations

### Error Handling

I implemented the error handling mechanism:
- Defined the `errno` variable to store error codes
- Ensured proper error code setting for all functions

## Implementation Details

### Syscall Interface

All functions are built directly on top of Linux syscalls, using inline assembly to make the appropriate syscall invocations. For example, the file operations use syscalls like `sys_open`, `sys_close`, and `sys_read`.

### Memory Management Architecture

The memory allocator uses a combination of strategies:
- For small allocations, it manages chunks of memory efficiently
- For larger allocations, it uses memory mapping via the `mmap()` syscall
- The implementation includes proper alignment handling for different architectures

### Optimizations

Several optimizations were implemented:
- Fast paths for common operations
- Efficient string comparison techniques
- Memory operations that handle alignment issues properly
- Cache-friendly memory allocation strategies

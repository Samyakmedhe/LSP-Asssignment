# Shared Library – MyStrlen (LSP Assignment)

## Problem Statement
Write a program in C to create a shared library `libmystring.so` which implements the function:

```c
int MyStrlenX(const char *str);

File Structure
.
├── client.c          // Client program
├── mystring.c        // Shared library source
├── mystring.h        // Header file
├── libmystring.so    // Shared library
├── Makefile
└── README.md


## Function Description  : 
int MyStrlen(const char *str)
*   Returns the length of the given string.
*   Does not use strlen().
*   Returns -1 if a NULL string is passed.
*   Uses manual character traversal.

## Build shared library and client
    make run

## Clean generated files
    make clean
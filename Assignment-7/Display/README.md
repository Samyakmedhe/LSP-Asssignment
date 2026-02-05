# Shared Library – Display String (LSP Assignment)

## Problem Statement
Write a program in C to create a shared library `libdisplay.so` which contains:


### Requirements
1. Client accepts a string from the user
2. Client calls `Display()` from the shared library
3. Library displays:
   - The string
   - Total number of characters

---

## File Structure
├── client.c
├── display.c
├── display.h
├── libdisplay.so
├── Makefile
└── README.md



---

## Function Description

### Display(char *str)
- Prints the given string
- Counts and displays total number of characters

---

## Compilation Steps

### Build shared library and client

make


Run program : 
    make run

Clean build files :
    make clean
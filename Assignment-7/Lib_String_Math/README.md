# LSP Assignment – Shared Libraries (String & Math)

## Objective
To create two shared libraries in C:
1. **libmystring.so** – implements major `string.h` functions
2. **libmymath.so** – implements major `math.h` functions

A menu-driven client program is used to call functions from these shared libraries.

---

## Project Structure
.
├── client.c
├── mystring.c
├── mystring.h
├── mymath.c
├── mymath.h
├── libmystring.so
├── libmymath.so
├── Makefile
└── README.md



---

## String Library – `libmystring.so`

Implemented functions (without using `string.h`):

1. MyStrlen
2. MyStrcpy
3. MyStrncpy
4. MyStrcmp
5. MyStrncmp
6. MyStrcat
7. MyStrchr
8. MyStrstr
9. MyStrrev

Features:
- Manual character traversal
- Safe handling of NULL values
- Exam-oriented implementation

---

## Math Library – `libmymath.so`

Implemented functions (without using `math.h`):

1. MyAdd
2. MySub
3. MyMul
4. MyDiv
5. MyPow
6. MySqrt (approximation method)
7. MyAbs
8. MyMax
9. MyMin
10. MyFactorial
11. MyGCD
12. MyLCM

---

## Client Program
- Menu-driven interface
- Allows user to select any string or math function
- Calls functions from shared libraries
- Displays result on terminal

---

## Build & Run Instructions

### Compile shared libraries and client

## Run the program
    make

## Clean compiled files
    make clean

### Sample Output
========== MAIN MENU ==========
1. String Functions
2. Math Functions
3. Exit
Enter choice : 2

----- Math Functions -----
1. MyAdd
2. MySub
3. MyMul
4. MyDiv
Enter choice : 1
Enter two numbers : 10 20
Result : 30

# Function Pointers using dlsym() in C

## 📌 Objective
To demonstrate **dynamic loading of a shared library** in C and the use of
**function pointers** with `dlsym()` by storing multiple function addresses
in an array and invoking them at runtime.

---

## 🧩 Operations Implemented
The shared library provides the following arithmetic operations:
- Addition
- Substraction
- Multiplcation

---

## 📂 Project Structure
FunctionPointer/
│
├── Server.c // Shared library source
├── client.c // Client program
├── Makefile
└── README.md




---

## 📄 File Description

### Server.c
- Contains arithmetic functions
- Compiled into a shared library (`libserver.so`)
- Functions exported:
  - `Addition(int, int)`
  - `Substraction(int, int)`
  - `Multiplcation(int, int)`

### client.c
- Accepts two integers from the user
- Loads the shared library dynamically using `dlopen()`
- Retrieves function addresses using `dlsym()`
- Stores them in an array of function pointers
- Invokes functions dynamically
- Displays function addresses and results

### Makefile
- Builds the shared library and client program
- Runs the application
- Cleans generated files

---

## ⚙️ Compilation & Execution

### Build the project
```bash
make

make run 

make clean

🧠 Concepts Used
Dynamic Linking
Shared Libraries (.so)
dlopen(), dlsym(), dlclose()
Function pointers
Array of function pointers
Runtime function invocation
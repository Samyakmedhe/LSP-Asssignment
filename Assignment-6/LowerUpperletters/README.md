# Dynamic Loading of String Operations using dlsym()

## 📌 Objective
To demonstrate dynamic loading of a shared library in C that performs
string operations using `dlopen()` and `dlsym()`.

---

## 🧩 String Operations Implemented
- Count lowercase letters
- Count uppercase letters
- Count digits

---

## 📂 File Description

### StringCount.c
Implements string operation functions and is compiled into a shared library.

### client.c
- Accepts a string from the user
- Loads the shared library dynamically
- Retrieves function addresses using `dlsym()`
- Invokes functions at runtime

### Makefile
Automates compilation, execution, and cleanup.

---

## ⚙️ Build & Run

### Compile
```bash
make

make run

make clean

🧠 Concepts Used

Dynamic Linking
Shared Libraries (.so)
dlopen(), dlsym(), dlclose()
Function pointers

🖥️ Platform
Linux
GCC Compiler
libdl
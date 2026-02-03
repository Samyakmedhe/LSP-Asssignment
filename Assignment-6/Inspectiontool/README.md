# Mini Dynamic Library Inspection Tool

## 📌 Objective
To design and implement a mini inspection tool in C that dynamically loads
a shared library and checks whether a given symbol exists using `dlsym()`.

---

## ✨ Features
- Accepts shared library path as command-line argument
- Accepts symbol name as command-line argument
- Loads library using `dlopen()`
- Searches symbol using `dlsym()`
- Displays symbol address if found
- Displays appropriate error message otherwise

---

## 📂 File Description

### inspect.c
Implements the dynamic library inspection logic using:
- `dlopen()`
- `dlsym()`
- `dlerror()`
- `dlclose()`

### Makefile
Automates compilation and cleanup.

---

## ⚙️ Compilation

```bash
make

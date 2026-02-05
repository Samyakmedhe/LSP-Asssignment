# Perfect Number Shared Libraries (C)

## 📌 Aim
To create two shared libraries in C:
1. **libhelper.so** – contains helper logic
2. **libperfect.so** – uses helper library to check whether a number is perfect

A number is said to be **Perfect** if the sum of its proper divisors is equal to the number itself.
Example: 28 → 1 + 2 + 4 + 7 + 14 = 28

---

## 📁 Project Structure

PerfectSharedLib/
│
├── helper.h
├── helper.c
├── perfect.h
├── perfect.c
├── main.c
├── Makefile
└── README.md
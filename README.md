# Datastructure-and-Algorithms

---

Just a coder sharpening my **data structures and algorithms** skills. This repo is my personal playground for learning, practicing, and implementing various DSA concepts.

Expect a mix of classic problems and my ongoing journey through fundamental computer science topics, primarily implemented in **C++**.

## Define Aliases

| Alias                                     | Meaning                         | Example                           |
| ----------------------------------------- | ------------------------------- | --------------------------------- |
| `using ull = unsigned long long;`         | unsigned 64-bit                 | `ull big = 1ULL << 63;`           |
| `using pii = pair<int, int>;`             | shorthand for pair              | `pii p = {1, 2};`                 |
| `using vi = vector<int>;`                 | shorthand for vector<int>       | `vi arr = {1,2,3};`               |
| `using vll = vector<long long>;`          | shorthand for vector<long long> | `vll nums = {10,20,30};`          |
| `using pll = pair<long long, long long>;` | pair of long longs              | `pll p = {1000000, 2000000};`     |
| `using vvi = vector<vector<int>>;`        | 2D vector shorthand             | `vvi grid(3, vector<int>(3, 0));` |


# Operator Performance and CPU Cost Guide (C++)

This document provides a **performance overview** of common C++ operators —  
their **relative CPU expense**, **execution behavior**, and **optimization notes**.

---

## Overview of Operators Expense

Different operators have different costs depending on whether they:
- Use **simple logic gates** (fast)
- Use **CPU arithmetic units** (medium)
- Use **division or modulo hardware** (slow)

---

## Relative Performance (Fast → Slow)

| Speed Rank | Operation Type | Examples | Typical CPU Cycles | Notes |
|-------------|----------------|-----------|--------------------|--------|
| **Bitwise** | `&`, `|`, `^`, `~`, `<<`, `>>` | 1–2 cycles | Extremely fast — single hardware instruction |
| **Logical / Comparison** | `==`, `!=`, `<`, `>`, `<=`, `>=`, `&&`, `\|\|` | 1–3 cycles | Fast; may depend on branching |
| **Addition / Subtraction** | `+`, `-`, `++`, `--` | 1–3 cycles | Very fast — uses ALU |
| **Multiplication** | `*` | 3–5 cycles | Hardware multiply — slightly slower |
| **Division / Modulo** | `/`, `%` | 20–40 cycles | Most expensive arithmetic operations |
| **Assignment / Compound** | `=`, `+=`, `-=`, `*=`, `/=`, `%=` | 1–3 cycles | Includes cost of underlying arithmetic |
| **Memory Access** | `[]`, `*ptr`, object field access | Depends | Can be fast or slow (cache/memory latency) |

---

## Arithmetic Operators

| Operator | Meaning | Relative Cost | Notes |
|-----------|----------|----------------|-------|
| `+` | Addition | Fast | Constant time |
| `-` | Subtraction | Fast | Constant time |
| `*` | Multiplication | Medium | Hardware multiply, slightly slower |
| `/` | Division | Slow | CPU-intensive, 20–30 cycles |
| `%` | Modulo (Remainder) | Very Slow | Uses division internally |
| `++` / `--` | Increment / Decrement | Fast | Simple add/sub operation |

---

## Bitwise Operators

| Operator | Meaning | Relative Cost | Notes |
|-----------|----------|----------------|-------|
| `&` | AND | Fast | 1 cycle; used for even/odd check |
| `|` | OR | Fast | 1 cycle |
| `^` | XOR | Fast | 1 cycle |
| `~` | NOT | Fast | Single-bit inversion |
| `<<` | Left Shift | Fast | Multiplication by 2ⁿ |
| `>>` | Right Shift | Fast | Division by 2ⁿ (integer truncation) |

---



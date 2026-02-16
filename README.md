### 🔢 push_swap – 42 Project

## 📌 Description
**push_swap** is an algorithmic project from **1337 / 42 Network**.  
The objective is to sort a stack of integers using a limited set of operations while minimizing the number of moves.

This project focuses on **algorithm design**, **data structures**, and **performance optimization**.

## 🎯 Objectives
- Understand and manipulate stacks
- Design an efficient sorting algorithm
- Optimize the number of operations
- Handle errors and invalid input
- Respect the 42 Norm

## 🧱 Stacks
The program manipulates two stacks:
- **Stack A**: contains the numbers to sort
- **Stack B**: used as auxiliary storage

## 🛠️ Allowed Operations
- `sa`, `sb`, `ss` – swap the first two elements
- `pa`, `pb` – push between stacks
- `ra`, `rb`, `rr` – rotate stacks
- `rra`, `rrb`, `rrr` – reverse rotate stacks

## 🧪 Program Usage
```bash
./push_swap 4 67 3 87 23
```
The program outputs a list of instructions that sort the numbers in ascending order.

## ⚙️ Compilation
```bash
make
```
# Executable generated:
```bash
push_swap
```

## 🧠 Algorithm Strategy

- The implemented solution includes:

- Specific handling for small sets (≤ 5 elements)

- Chunk-based or radix-based sorting for large sets

- Efficient use of stack operations to minimize moves

## 📏 Rules & Constraints

- Written in C

- Only allowed operations are used

- No memory leaks

- Proper error handling

- Fully compliant with the 42 Norm

## 👨‍💻 Author
EL MEHDI ENASSIRI, 1337 School – 42 Network
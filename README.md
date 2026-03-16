# 🧮 MatrixToolkit: C++ Linear Algebra Suite

> **A high-precision C++ library for advanced matrix calculus and digital signal processing foundations.**

## 📌 Features
* **Matrix Arithmetic:** Efficient $O(n^3)$ multiplication, addition, and subtraction.
* **Algebraic Solvers:** Determinant calculation and Matrix Inversion using the **Adjugate Method**.
* **Signal Processing:** 2D Convolution engine (Kernel-to-Image mapping).
* **Transformations:** Transposition and Power Elevation.

## 💻 Usage
The program features a CLI (Command Line Interface) menu:
1. Select operation (1-9).
2. Input matrix dimensions and elements.
3. View formatted results in the console.

---
**Developed for educational and engineering purposes.**

## 🛠️ Development Journey & Problem Solving

### 🏗️ Phase 1: Basic Arithmetic to Complexity
The project started as a simple calculator for sums and differences. The challenge was scaling this to handle **Matrix Inversion**.
* **Difficulty:** Implementing the Adjugate method required a recursive-style thinking to handle sub-matrices (minors and cofactors).
* **Evolution:** I refactored the code to use a modular approach, where the `determinant()` function could be reused for different matrix sizes, ensuring code reusability.

### 🧩 Phase 2: Memory & Static Allocation
Handling large 2D arrays (50x50) in C++ can lead to stack overflow if not managed correctly.
* **Refinement:** I optimized the global and local matrix declarations to ensure stability during high-intensity calculations like **Power Elevation** and **2D Convolution**.

### 🖼️ Phase 3: Bridge to Image Processing
The addition of the **Convolution** function marked the transition from pure math to practical engineering. Understanding how a kernel slides over an image matrix was a significant conceptual leap that I successfully implemented to mimic digital filter behavior.

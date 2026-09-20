# Exercise 6 - Array Multiplication Using Strip Mining and OpenMP

## Description

This exercise performs element-wise multiplication of two arrays containing 1,000,000 elements.

For each element, the program calculates:

`C[i] = A[i] * B[i]`

The arrays are initialized with `A[i] = 2.0` and `B[i] = 3.0`, so every element in the result array should be `6.0`.

## Strip Mining

The array is divided into fixed-size strips using:

`STRIP_SIZE = 1024`

Instead of processing all 1,000,000 elements as one loop, the program processes the array in blocks of 1024 elements. The final strip is adjusted if it contains fewer than 1024 elements.

## OpenMP Parallelization

The directive:

`#pragma omp parallel for`

distributes the strips among the available OpenMP threads.

The program was executed using 2 OpenMP threads.

## SIMD

Inside each strip, the directive:

`#pragma omp simd`

allows the compiler to perform the element-wise multiplication using SIMD vectorization.

The strip size of 1024 is a multiple of common SIMD vector widths, making it suitable for SIMD processing.

## Result

The program successfully processed an array of 1,000,000 elements.

Result verification: `PASSED`

Execution time: `0.004202 seconds`

The program was compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

The complete output is available in `result_exercise06.txt`.

# Exercise 1 - OpenMP Barrier

## Description

The `#pragma omp barrier` directive creates a synchronization point for all threads in the parallel region.

In this program, each thread first prints its thread number and then reaches the barrier. Every thread must reach the barrier before any thread can continue to the statements after it.

After all threads reach the barrier, they continue execution and print the "Outside Barrier" and "Hi again" messages. The order in which the threads execute after the barrier is not guaranteed.

## Result

The program was compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

The output is available in `result_exercise01.txt`.

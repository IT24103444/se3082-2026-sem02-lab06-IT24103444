# Exercise 4 - OpenMP Parallel For and Collapse

## Part 1 - Parallel For

The first version uses:

`#pragma omp parallel for`

This directive parallelizes the outer loop. The outer loop has 5 iterations where `r` ranges from 1 to 5. Each thread that receives an `r` value executes all 10 iterations of the inner `k` loop for that value.

The program was executed using 2 OpenMP threads.

In the obtained result:

- Thread 0 handled `r = 1, 2, 3`, giving it 30 `(r, k)` iterations.
- Thread 1 handled `r = 4, 5`, giving it 20 `(r, k)` iterations.

The output is available in `result_exercise04_normal.txt`.

## Part 2 - Collapse(2)

The second version uses:

`#pragma omp parallel for collapse(2)`

The `collapse(2)` clause combines the two nested loops into a single iteration space. Since the outer loop has 5 iterations and the inner loop has 10 iterations, there are 50 combined `(r, k)` iterations.

With 2 threads, the obtained result distributed these 50 iterations evenly:

- Thread 0 handled 25 iterations, from `(r=1, k=1)` to `(r=3, k=5)`.
- Thread 1 handled 25 iterations, from `(r=3, k=6)` to `(r=5, k=10)`.

Therefore, `collapse(2)` allows the iterations of both nested loops to be distributed across the threads instead of parallelizing only the outer loop.

The output is available in `result_exercise04_collapse.txt`.

## Result

Both versions were compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

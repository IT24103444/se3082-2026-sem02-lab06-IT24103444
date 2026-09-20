# Exercise 5 - OpenMP Task Parallelization

## Description

The serial Fibonacci function was parallelized using OpenMP task parallelization.

The two recursive Fibonacci calls are created as separate tasks using:

`#pragma omp task`

This allows the OpenMP threads to execute recursive Fibonacci calculations as tasks.

The `#pragma omp taskwait` directive waits until both recursive tasks are completed before adding their results and returning the Fibonacci value.

In the main function, a parallel region creates the OpenMP threads. The `#pragma omp single` directive ensures that only one thread starts the initial Fibonacci calculation. The tasks created during the recursive calls can then be executed by the available threads.

## Result

The program calculated:

`Fibonacci(20) = 6765`

The program was compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

The output is available in `result_exercise05.txt`.

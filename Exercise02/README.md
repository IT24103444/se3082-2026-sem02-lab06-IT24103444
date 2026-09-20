# Exercise 2 - OpenMP Single

## Description

The `#pragma omp single` directive specifies that the following block of code should be executed by only one thread in the parallel region.

In this program, both threads first print their thread numbers. When they reach the `single` section, only one of the threads executes the statements inside it. The thread that executes the single section is not necessarily thread 0.

In this execution, thread 1 executed the single section and printed "Inside Single # 1" and "Exiting Single".

After the single section is completed, both threads continue execution and print their "Hi again" messages.

## Result

The program was compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

The output is available in `result_exercise02.txt`.

# Exercise 7 - Mandelbrot Set Using OpenMP

## Serial Version

The original Mandelbrot program calculates the area of the Mandelbrot set using nested loops.

The serial program produced:

`Area of Mandlebrot set = 1.50928453 +/- 0.00075464`

This result was used as the baseline for checking the correctness of the parallel implementation.

## OpenMP Parallelization

The outer loop was parallelized using:

`#pragma omp parallel for`

The variables `j`, `iter`, `ztemp`, `z`, and `c` are declared as private because each thread requires its own copy while processing its assigned iterations.

The variable `numoutside` is updated by multiple threads. Therefore, the following reduction is used:

`reduction(+:numoutside)`

This gives each thread a private value for `numoutside` and combines the values at the end of the parallel loop.

The outer loop variable `i` is automatically private because it is the iteration variable of the OpenMP parallel for loop.

## Thread Comparison

The parallel program was tested with 1, 2, 3, and 4 OpenMP threads.

| Threads | Area | Error | Execution Time |
|---|---|---|---|
| 1 | 1.50928453 | 0.00075464 | 10.178595 seconds |
| 2 | 1.50928453 | 0.00075464 | 8.655047 seconds |
| 3 | 1.50928453 | 0.00075464 | 6.160516 seconds |
| 4 | 1.50928453 | 0.00075464 | 5.442410 seconds |

The area and error remained identical for all thread counts, showing that the parallel implementation produced the same result as the serial implementation.

The AWS EC2 instance used for testing has 2 vCPUs. Therefore, the 3-thread and 4-thread tests use more OpenMP threads than the available vCPUs.

## OpenMP Scheduling

A separate version using:

`schedule(runtime)`

was used to compare different OpenMP scheduling methods with 2 threads.

| Schedule | Execution Time |
|---|---|
| Static | 8.578982 seconds |
| Dynamic | 5.075004 seconds |
| Guided | 5.394847 seconds |

All scheduling methods produced the same Mandelbrot area and error.

Static scheduling assigns loop iterations to threads in a predetermined manner.

Dynamic scheduling assigns iterations to threads as they become available. This can help balance the Mandelbrot workload because different points may require different numbers of iterations.

Guided scheduling also assigns work dynamically, but the chunk size decreases as the computation progresses.

## Result Files

- `result_exercise07_serial.txt` contains the serial result.
- `result_exercise07_parallel.txt` contains the 1, 2, 3, and 4 thread results.
- `result_exercise07_schedule.txt` contains the scheduling comparison results.

# Exercise 3 - OpenMP Master

## Description

The `#pragma omp master` directive specifies that the following block of code is executed only by the master thread, which is thread 0.

In this program, all threads first print their thread numbers. When they reach the `master` section, only thread 0 executes the statements inside it.

Unlike the `single` directive, the `master` directive does not have an implicit barrier. Therefore, the other threads do not have to wait for the master thread to finish the master section before continuing.

In this execution, thread 1 continued and printed its "Hi again" message while thread 0 executed the master section.

## Result

The program was compiled and executed using OpenMP with 2 threads on an AWS EC2 Linux instance.

The output is available in `result_exercise03.txt`.

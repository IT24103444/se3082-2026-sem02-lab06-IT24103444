Molecular Dynamics Exercise

The Lab 06 README states that the Molecular Dynamics source code can
be found in */MolDyn/.

I could not locate the MolDyn directory or the required Molecular
Dynamics source files in my Lab 06 project. Therefore, I was unable
to modify, compile, and execute the Molecular Dynamics program.

If the Molecular Dynamics source code is available, I would complete
the exercise using the following procedure:

1. Locate and open the forces.[f|c|f90] source file.

2. Parallelize the outer loop using the appropriate OpenMP parallel
   loop directive. For C:

   #pragma omp parallel for

3. Identify the required private variables for the parallel loop.

4. Identify the two reduction variables mentioned in the exercise
   instructions and include them in the reduction clause.

5. Identify the variable inside the loop that requires synchronized
   updating and protect the update using:

   #pragma omp critical

6. Compile the program with OpenMP enabled.

   For a C implementation, an example command would be:

   gcc -fopenmp main.c forces.c -o moldyn

   The exact compilation command would depend on the available
   Molecular Dynamics source files.

7. Run the serial version first and record its output and execution
   time.

8. Run the parallel version using 2, 3, and 4 threads:

   export OMP_NUM_THREADS=2
   ./moldyn

   export OMP_NUM_THREADS=3
   ./moldyn

   export OMP_NUM_THREADS=4
   ./moldyn

9. Compare the outputs from 2, 3, and 4 threads with the serial output
   to check that the results are consistent.

10. Test the schedule clause:

    schedule(static,n)

    using different values of n and compare the performance.

11. Measure the execution time using omp_get_wtime() as described in
    the Lab 06 README.

The actual private variables, two reduction variables, and the variable
requiring the critical section would be determined by examining the
forces.[f|c|f90] source code.

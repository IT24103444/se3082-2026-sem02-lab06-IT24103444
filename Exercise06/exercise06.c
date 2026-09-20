#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define STRIP_SIZE 1024

int main() {
    double *A = malloc(N * sizeof(double));
    double *B = malloc(N * sizeof(double));
    double *C = malloc(N * sizeof(double));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        A[i] = 2.0;
        B[i] = 3.0;
    }

    double start = omp_get_wtime();

    #pragma omp parallel for
    for (int strip = 0; strip < N; strip += STRIP_SIZE) {

        int end = strip + STRIP_SIZE;

        if (end > N)
            end = N;

        #pragma omp simd
        for (int i = strip; i < end; i++) {
            C[i] = A[i] * B[i];
        }
    }

    double stop = omp_get_wtime();

    int correct = 1;

    for (int i = 0; i < N; i++) {
        if (C[i] != 6.0) {
            correct = 0;
            break;
        }
    }

    printf("Array size: %d\n", N);
    printf("Strip size: %d\n", STRIP_SIZE);
    printf("Threads used: %d\n", omp_get_max_threads());
    printf("Result verification: %s\n", correct ? "PASSED" : "FAILED");
    printf("Execution time: %f seconds\n", stop - start);

    free(A);
    free(B);
    free(C);

    return 0;
}

#pragma warning(disable: 4244)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

#define THREAD_COUNT 1

double* rand_doubles(time_t seed, int num_rands) {
	int i;
	srand(seed);
	double *rands = (double*)malloc(sizeof(double) * num_rands);
	for (i = 0; i < num_rands; i++)
		rands[i] = (double)rand() * (double)rand() / RAND_MAX * 2.0 - 1.0;

	return rands;
}

void HomeworkProblem5_10(int n) {
#pragma omp parallel num_threads(THREAD_COUNT)
	{
		int i;
		double my_sum = 0.0;
		for (i = 0; i < n; i++) {
#pragma omp atomic
			my_sum += sin(i);
		}
	}
}

void HomeworkProblems6_8() {

	// Initialize the RNG.
	srand(time(NULL));
	int size = rand();

	// Declare variables
	double *x, *y;
	double alpha;

	// Initialize X, Y, and α
	alpha = rand();
	x = rand_doubles(time(NULL), size);
	y = rand_doubles(time(NULL), size);

	// Cleanup
	free(x);
	free(y);
}
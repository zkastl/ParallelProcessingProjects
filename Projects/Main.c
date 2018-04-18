#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "Homework.h"
#include "ArrayUtils.h"
#include "Sorting.h"

#define NUM_RANDS 1000000
#define NUM_THREADS 4

void Sorting()
{
	double start_time, execution_time;

	printf("Generating a random list of %d elements.....", NUM_RANDS);
	int* list = RandomList(NUM_RANDS);
	printf("DONE!\n");

	printf("Copying this list for later.....");
	int* copy = CopyList(list, NUM_RANDS);
	printf("DONE!\n");

	printf("***Sorting your list with Serial Quicksort...");
	start_time = omp_get_wtime();
	Quicksort(list, 0, (NUM_RANDS - 1));
	execution_time = omp_get_wtime() - start_time;
	if (PrintArray)
		printf("List sorted in %lf seconds!***\n", execution_time);
	else
		printf("List unsuccessfully sorted...\n");

	printf("***Sorting your list with OpenMP Quicksort...");
	start_time = omp_get_wtime();
	QuicksortParallel(copy, 0, (NUM_RANDS - 1), NUM_RANDS);
	execution_time = omp_get_wtime() - start_time;
	if (PrintArray)
		printf("List sorted in %lf seconds!***\n", execution_time);
	else
		printf("List unsuccessfully sorted...\n");

	printf("***Cleaning up memory...");
	free(list);
	free(copy);
	printf("DONE***\n\n***COMPLETE!***");
}

int main(int argc, char* argv[])
{
	//HomeworkProblems6_8();
	Sorting();

	return 0;
}

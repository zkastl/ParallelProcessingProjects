#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#include "ArrayUtils.h"
#include "Sorting.h"

#define NUM_THREADS 4
#define MAX_LEN 262144000

/* 
Main Sorting driver method. 
This will sort a randomly generated array of integers in the 
range of 0-500 in increasing numerical order using two versions of quicksort. The
first is a simple traditional quicksort, performed in serial. The second is a OpenMP
modified version of quicksort that will run in parallel using the number of threads
defined in the above macro. Quicksort selects the pivot that is the midpoint of the array
in both serial and parallel. 
*/
void Sorting(int num_to_sort)
{
	/* Declare variables */
	double start_time, serial_execution_time, parallel_execution_time;
	int parallel_faster = 0;

	/* Generate a list of random numbers to sort. */
	int* list = RandomList(num_to_sort);

	/* Copy the list for comparison to the serial sort. */
	int* copy = CopyList(list, num_to_sort);

	/* Sort the array using a traditional Quicksort method. Calculate the sort time. */
	start_time = omp_get_wtime();
	Quicksort(list, 0, (num_to_sort - 1));
	serial_execution_time = omp_get_wtime() - start_time;

	/* Sort the copy of the array using the modified openmp quicksort; this should
	 * be compatable with OpenMP >=2.0. Calcualte the sort time */
	start_time = omp_get_wtime();
	QuicksortParallel(copy, 0, (num_to_sort - 1), NUM_THREADS);
	parallel_execution_time = omp_get_wtime() - start_time;
	if (!PrintArray(copy, num_to_sort, 0))
		/* Report to standard output the number sorted, the times it takes*/
		printf("%d, %lf, %lf\n", num_to_sort, serial_execution_time, parallel_execution_time);

	/* Clean up the heap. */
	free(list);
	free(copy);
}

/* Special driver function. This function will run the quicksort algorithm from 10^1 to
 * 10^9 values. Each sorting will return whether or not the serial or the parallel version
 * is faster in order to determine just when you should use parallel processing.
 * This will be not 100% accurate, due to the random nature of the list and its effect
 * on quicksort's performance. */
void ProgressiveSorting() 
{
	printf("Array Size, Sort Time with Quicksort in Series, Sort Time with Quicksort in Parallel\n");
	int list_size;
	for(list_size = 10; list_size < 1000000000; list_size+=10000) {
		Sorting(list_size);
	}
}

/* Main method. */
int main(int argc, char* argv[])
{
	ProgressiveSorting();
	return 0;
}

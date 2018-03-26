#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#ifdef _OPENMP
	#include <omp.h>
#endif

#include "ArrayUtils.h"
#include "BubbleSort.h"
#include "Quicksort.h"
#include "Defs.h"

double AreaTrapezoidal(int left_bound, int right_bound, int iterations, double(*func_ptr)(double))
{
	/* Function is assumed to be calculaton function that takes in a double
		and returns a double back. */
	int i;
	double x_i;
	double h = (right_bound - left_bound) / iterations;
	double approx = (func_ptr(left_bound) + func_ptr(right_bound)) / 2.0;
	for (i = 0; i < iterations; i++) {
		x_i = left_bound + i * h;
		approx += func_ptr(x_i);
	}
	approx = h * approx;

	return approx;
}

unsigned long long* FibbonacciSequence(int num_fibs)
{
	if (num_fibs < 2) {
		printf("Not enough terms to generate a sequence; number of terms must be at least 2");
	}
	unsigned long long *fibs = (unsigned long long*)malloc(num_fibs * sizeof(unsigned long long));
	fibs[0] = 1;
	fibs[1] = 1;

	printf("First %d Fibbonacci numbers: %llu %llu ", num_fibs, fibs[0], fibs[1]);
	for (int i = 2; i < num_fibs; i++)
	{
		fibs[i] = fibs[i - 1] + fibs[i - 2];
		printf("%llu ", fibs[i]);
	}
	printf("\n");

	return fibs;
}

void Sort(void (*sort)(int*, int, int), int* list, int low, int high, BOOL print)
{
	if (print) printf("Unsorted List: ");
	if (print) PrintArray(list);
	time_t startTime = time(NULL);
	sort(list, low, high);
	printf("List sorted in %d seconds \n", (int)(time(NULL) - startTime));
	if (print) printf("Sorted List: ");
	if (print) PrintArray(list);
	printf("\n");
}

void SortingARandomList()
{
	int* list = RandomList();
	int* copy = CopyList(list);

	Sort(Quicksort, list, 0, NUM_RANDS - 1, false);
	/*Sort(BubbleSort, copy, NULL, NUM_RANDS, false);*/

	free(list);
	free(copy);
}

void Hello()
{
	int my_rank, thread_count;
#   ifdef _OPENMP
	my_rank = omp_get_thread_num();
	thread_count = omp_get_num_threads();
#	else
	my_rank = 0;
	thread_count = 1;
#	endif

	printf("Hello from thread %d of %d!\n", my_rank, thread_count);
}

void HelloParallel(int argc, char* argv[])
{
	int thread_count = 1;
	if (argc > 1 && (int)argv[1] > 1)
		thread_count = strtol(argv[1], NULL, 10);
	#pragma omp parallel num_threads(thread_count)
	Hello();

	return;
}

long double Pi(unsigned long long num_points) 
{
	srand((unsigned int)time(NULL));
	int count = 0;
	int i;
	long double x, y, z, pi;
	for (i = 0; i < num_points; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x * x + y * y;
		if (z <= 1) count++;
	}
	pi = (long double)count / num_points * 4;
	printf("# of trials = %lld, estimate pi to be %g \n", num_points, pi);

	return pi;
}

int main(int argc, char* argv[])
{
	if (argc > 1 && argv[1] == "--h")
		printf("Example: ./Assignment1.exe <num_threads>\n");

	HelloParallel(argc, argv);
	SortingARandomList();
	return(0);
}
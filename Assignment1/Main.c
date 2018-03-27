#pragma warning(disable: 4996)

#ifdef _OPENMP
	#include <omp.h>
#endif
#include <stdio.h>	
#include <stdlib.h>

#include "ArrayUtils.h"
#include "Defs.h"
#include "MathAlgorithms.h"
#include "Sorting.h"

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

int main(int argc, char* argv[])
{
	if (argc > 1 && argv[1] == "--h")
		printf("Example: ./Assignment1.exe <num_threads>\n");

	return(0);
}
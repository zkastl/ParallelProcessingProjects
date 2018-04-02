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

int main(int argc, char* argv[])
{
	int i;
	if (argc > 1 && argv[1] == "--h")
		printf("Example: ./Assignment1.exe <num_threads>\n");
	//for(i = 0; i < 100; i++)
		//SortingARandomList();
#ifdef _OPENMP
	printf("_OPENMP : %d\n", _OPENMP);
#endif

	return(0);
}
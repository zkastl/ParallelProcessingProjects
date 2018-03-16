#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Quicksort.h"

#define NUM_RANDS 1000000

void PrintArray(int* A);

int main()
{
	/* Initialize values */
	srand(time(NULL));
	int idx = 0;
	int *list = (int*)malloc(NUM_RANDS * sizeof(int));

	for (idx = 0; idx < NUM_RANDS; idx++) {
		list[idx] = rand() % 500;
	}

	printf("Original list: ");
	/*PrintArray(list);*/

	time_t startTime = time(NULL);
	QuickSort(list, 0, NUM_RANDS-1);
	printf("%d seconds ",(time(NULL) - startTime));
	
	printf("Sorted List: ");
	/*PrintArray(list);*/

	free(list);
	return(0);
}

void PrintArray(int *A)
{
	int i;
	printf("{ ");
	for (i = 0; i < NUM_RANDS; i++) {
		printf("%d ", A[i]);
	}
	printf("}\n");
}
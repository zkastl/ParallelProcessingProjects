#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include "Quicksort.h"

#define NUM_RANDS 20

void PrintArray(int* A);

int main(int argc, char *argv[])
{
	/* Initialize values */
	srand(time(NULL));
	int idx = 0;
	int list[NUM_RANDS] = { 0 };

	for (idx = 0; idx < NUM_RANDS; idx++) {
		list[idx] = rand() % 500;
	}

	printf("Original list: ");
	PrintArray(list);
	QuickSort(list, 0, NUM_RANDS-1);
	printf("Sorted List: ");
	PrintArray(list);

	return 0;
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
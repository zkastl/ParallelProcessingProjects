#include <stdio.h>
#include <stdlib.h>

#include "ArrayUtils.h"
#include "Defs.h"

int* CopyList(int* list)
{
	int* copy = (int*)malloc(NUM_RANDS * sizeof(int));
	for (int i = 0; i < NUM_RANDS; i++) {
		copy[i] = list[i];
	}
	return copy;
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

int* RandomList()
{
	/* Initialize values */
	srand((unsigned int)time(NULL));
	int *list = (int*)malloc(NUM_RANDS * sizeof(int));

	for (int idx = 0; idx < NUM_RANDS; idx++) {
		list[idx] = rand() % 500;
	}

	return list;
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
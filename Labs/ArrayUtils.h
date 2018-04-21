#pragma once
#include <stdlib.h>

int* CopyList(int* list, int size)
{
	int* copy = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		copy[i] = list[i];
	}
	return copy;
}

int PrintArray(int *A, int size, int print)
{
	int outOfOrder = 0;
	int prev = -1;
	int i;

	if(print) printf("[ ");
	for (i = 0; i < size; i++) {
		if(print) printf("%d ", A[i]);
		if (A[i] < prev)
			outOfOrder = 1;
		prev = A[i];
	}
	if(print) printf("]\n\n");
	printf("This array was out of order? %c\n", (outOfOrder ? 'Y' : 'N'));

	return outOfOrder;
}

int* RandomList_Ints(int num_rands)
{
	/* Initialize values */
	srand((unsigned int)time(NULL));
	int *list = (int*)malloc(num_rands * sizeof(int));

	for (int idx = 0; idx < num_rands; idx++) {
		list[idx] = rand();
	}

	return list;
}
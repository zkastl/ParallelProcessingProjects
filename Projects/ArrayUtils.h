#pragma once

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
	if (print > 0 )
		printf("{ ");
	for (i = 0; i < size; i++) {
		if (A[i] < prev)
			outOfOrder = 1;
		prev = A[i];
		if (print > 0)
			printf("%d ", A[i]);
	}
	if (print > 0)
		printf("}\n");
	printf("%c", (outOfOrder ? 'Y' : 'N'));

	return outOfOrder;
}

int* RandomList(int num_rands)
{
	/* Initialize values */
	srand((unsigned int)time(NULL));
	int *list = (int*)malloc(num_rands * sizeof(int));

	for (int idx = 0; idx < num_rands; idx++) {
		list[idx] = rand() % 500;
	}

	return list;
}
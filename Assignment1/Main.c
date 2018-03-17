#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { false, true } BOOL;
#define NUM_RANDS 10

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
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

int* MatrixMultiply(int* mtx1, int* mtx2, int mtx1_rows, int mtx1_cols, int mtx2_cols)
{
	return NULL;
}

int* Transpose(int* mtx)
{
	return NULL;
}

void BubbleSort(int* list, int list_len)
{
	BOOL swapped = true;
	while(swapped)
	{
		swapped = false;
		for (int i = 0; i < list_len - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				Swap(&list[i], &list[i + 1]);
				swapped = true;
			}
		}
	}
}

int Partition(int *A, int low, int high)
{
	int pivot = high;
	int index = low;

	while (index < pivot)
	{
		if (A[index] < A[pivot]) {
			index++;
		}
		else
		{
			Swap(&A[index], &A[pivot - 1]);
			Swap(&A[pivot - 1], &A[pivot]);
			pivot--;
		}
	}

	return pivot;
}

void Quicksort(int *A, int low, int high)
{
	if (low < high)
	{
		int part = Partition(A, low, high);
		Quicksort(A, low, part - 1);
		Quicksort(A, part + 1, high);
	}
}

int main()
{
	/* Initialize values */
	srand((unsigned int)time(NULL));
	int *list = (int*)malloc(NUM_RANDS * sizeof(int));

	for (int idx = 0; idx < NUM_RANDS; idx++) {
		list[idx] = rand() % 500;
	}

	printf("Original list: ");
	PrintArray(list);

	time_t startTime = time(NULL);
	/*Quicksort(list, 0, NUM_RANDS - 1);*/
	BubbleSort(list, NUM_RANDS);
	printf("%d seconds ", (int)(time(NULL) - startTime));

	printf("Sorted List: ");
	PrintArray(list);

	free(list);
	return(0);
}
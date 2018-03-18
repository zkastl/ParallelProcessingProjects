#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { false, true } BOOL;
#define NUM_RANDS 10000000

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
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

unsigned long long* FibbonacciSequence(int num_fibs)
{
	if (num_fibs < 2) {
		printf("Not enough terms to generate a sequence; number of terms must be at least 2");
	}
	unsigned long long *fibs = (unsigned long long*)malloc(num_fibs * sizeof(unsigned long long));
	fibs[0] = 1;
	fibs[1] = 1;

	printf("First %d Fibbonacci numbers: %d %d ", num_fibs, fibs[0], fibs[1]);
	for (int i = 2; i < num_fibs; i++)
	{
		fibs[i] = fibs[i - 1] + fibs[i - 2];
		printf("%d ", fibs[i]);
	}
	printf("\n");

	return fibs;
}

void SortingAssignments()
{
	int* list = RandomList();
	int* copy = CopyList(list);
	
	printf("Original list: ");
	/*PrintArray(list);	*/
	time_t startTime = time(NULL);
	Quicksort(list, 0, NUM_RANDS - 1);
	printf("List sorted in %d seconds \n", (int)(time(NULL) - startTime));
	printf("Sorted List: ");
	/*PrintArray(list);	*/
	printf("\n");

	printf("Original list copy: ");
	/*PrintArray(list);	*/
	startTime = time(NULL);
	BubbleSort(copy, NUM_RANDS);
	printf("List sorted in %d seconds \n", (int)(time(NULL) - startTime));
	printf("Sorted List: ");
	/*PrintArray(list);	*/
	printf("\n");

	free(list);
	free(copy);
}

void FibbonacciAssignments()
{
	int num_fibs;
	printf("\nEnter the number of fibbonacci numbers to generate:\n");
	scanf("%d", &num_fibs);
	FibbonacciSequence(num_fibs);
}

int main()
{
	SortingAssignments();
	FibbonacciAssignments();

	return(0);
}
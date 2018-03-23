#include "ArrayUtils.h"
#include "Quicksort.h"

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
#pragma once

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
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

void QuickSort(int *A, int low, int high)
{
	if (low < high)
	{
		int part = Partition(A, low, high);
		QuickSort(A, low, part - 1);
		QuickSort(A, part + 1, high);
	}
}

#ifdef _OPENMP
#include <omp.h>
#endif

#include <stdio.h>	
#include <stdlib.h>
#include <time.h>

#include "ArrayUtils.h"
#include "Defs.h"
#include "Sorting.h"

void BubbleSort(int* list, int start, int list_len)
{
	BOOL swapped = true;
	while (swapped)
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

void Sort(void(*sort)(int*, int, int), int* list, int low, int high, BOOL print)
{
	if (print) printf("Unsorted List: ");
	if (print) PrintArray(list);
	time_t startTime = time(NULL);
	sort(list, low, high);
	printf("List sorted in %d seconds \n", (int)(time(NULL) - startTime));
	if (print) printf("Sorted List: ");
	if (print) PrintArray(list);
	printf("\n");
}

void SortingARandomList()
{
	int* list = RandomList();
	Sort(Quicksort, list, 0, NUM_RANDS - 1, false);
	free(list);

	/*int* copy = CopyList(list);
	Sort(BubbleSort, copy, NULL, NUM_RANDS, false);
	free(copy);*/
}

int Quicksort_Partition(int *A, int low, int high)
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
		int part = Quicksort_Partition(A, low, high);
		Quicksort(A, low, part - 1);
		Quicksort(A, part + 1, high);
	}
}

int Quicksort_Parallel(int * A, int low, int high)
{
	return 0;
}

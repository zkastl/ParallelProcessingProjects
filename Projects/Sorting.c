#include "Sorting.h"

BOOL forked = false;

void BubbleSort(int* list, int start, int list_len)
{
	BOOL swapped = true;
	while (swapped)
	{
		swapped = false;
		int i;
		for (i = 0; i < list_len - 1; i++)
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
	//int* copy = CopyList(list);
	Sort(QSP_internal, list, 0, NUM_RANDS - 1, true);

	free(list);
	//free(copy);
}

void Quicksort(int *A, int low, int high)
{
	if (low < high)
	{
		int pivot = high;
		int index = low;

		while (index < pivot)
		{
			if (A[index] < A[pivot])
				index++;
			else {
				Swap(&A[index], &A[pivot - 1]);
				Swap(&A[pivot - 1], &A[pivot]);
				pivot--;
			}
		}
		Quicksort(A, low, pivot - 1);
		Quicksort(A, pivot + 1, high);
	}
}

void QuicksortParallel(int *A, int low, int high, int thread_count)
{
	int cutoff = 1000;
	#pragma omp parallel num_threads(thread_count)
	{
		#pragma omp single nowait
		{
			QSP_internal(A, low, high, cutoff);
		}
	}
}

void QSP_internal(int *A, int low, int high, int cutoff)
{
	int i = low, j = high;
	int tmp;
	int pivot = A[(low + high) / 2];


	{
		/* PARTITION PART */
		while (i <= j) {
			while (A[i] < pivot)
				i++;
			while (A[j] > pivot)
				j--;
			if (i <= j) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
				i++;
				j--;
			}
		}

	}


	if (((high - low)<cutoff)) {
		if (low < j) { QSP_internal(A, low, j, cutoff); }
		if (i < high) { QSP_internal(A, i, high, cutoff); }

	}
	else {
		#pragma omp sections
		{
			#pragma omp section
			QSP_internal(A, low, j, cutoff);
			#pragma omp section
			QSP_internal(A, i, high, cutoff);
		}
	}
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
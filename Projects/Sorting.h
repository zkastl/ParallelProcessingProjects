#pragma once

void Swap(int *a, int *b);
void Quicksort(int *A, int low, int high);

void QuicksortParallel(int *A, int low, int high, int num_threads);
void QSP_internal(int *A, int low, int high, int cutoff);

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

/* Need explaination here about how I took this code and modified it for my purposes*/
/* https://github.com/eduardlopez/quicksort-parallel/blob/master/quicksort-omp.h */
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
	int pivot = A[(low + high) / 2];
	{
		/* Partition*/
		while (i <= j) {
			while (A[i] < pivot)
				i++;
			while (A[j] > pivot)
				j--;
			if (i <= j) {
				Swap(&A[i], &A[j]);
				i++;
				j--;
			}
		}

	}

	if (((high - low)<cutoff)) {
		if (low < j)
			QSP_internal(A, low, j, cutoff);
		if (i < high)
			QSP_internal(A, i, high, cutoff);
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
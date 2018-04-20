#pragma once

/* Declarations */
void Swap(int *a, int *b);
void Quicksort(int *A, int low, int high);
void QuicksortParallel(int *A, int low, int high, int num_threads);
void QSP_internal(int *A, int low, int high, int cutoff);

/* Implementations */

/* Serial Quicksort method. Uses the array's midpoint as the starting
 * pivot. */
void Quicksort(int *A, int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
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
		Quicksort(A, low, j);
		Quicksort(A, i, high);
	}
}

/* This method was inspired by:
 *		https://github.com/eduardlopez/quicksort-parallel/blob/master/quicksort-omp.h
 */
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

/* Internal method to be used in the parallelization. */
void QSP_internal(int *A, int low, int high, int cutoff)
{
	int i = low;
	int j = high;
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

	if (((high - low) < cutoff)) {
		if (low < j)
			QSP_internal(A, low, j, cutoff);
		if (i < high)
			QSP_internal(A, i, high, cutoff);
	}
	else {
		#pragma omp task
		QSP_internal(A, low, j, cutoff);

		#pragma omp task
		QSP_internal(A, i, high, cutoff);
	}
}

/* Simple Swap method. */
void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
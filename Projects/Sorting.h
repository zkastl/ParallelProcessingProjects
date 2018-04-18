#pragma once

void Swap(int *a, int *b);
void Quicksort(int *A, int low, int high);

void QuicksortParallel(int *A, int low, int high, int num_threads);
void QSP_internal(int *A, int low, int high, int cutoff);

void Quicksort(int *A, int low, int high)
{
	if (low < high)
	{
		int pivot = (low + high) / 2;
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

/* This method was inspired by:
 *		https://github.com/eduardlopez/quicksort-parallel/blob/master/quicksort-omp.h
 * Lopez's code is a slight modification of the serial quicksort method, shown in this file.
 * This code utilizes OpenMP >= 3.0 to divide the separate recursive portions of quicksort
 * into separate tasks. Since my version of C (MSVC) only supports OpenMP 2.0, a change was
 * required.
 * 
 * In this version, a modification of the version located at the link. The tasks pragma
 * was replaced with a sections pragma. It was a slight modification, but increases the
 * compatability with different compilers. */
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

		/* Unusable on OpenMP 2.0 */
		/*#pragma omp task
		QSP_internal(A, low, j, cutoff);

		#pragma omp task
		QSP_internal(A, i, high, cutoff);*/
	}
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
#pragma once
#include <omp.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayUtils.h"

void count_sort_serial(int* A, int n) {
	int i, j, count;
	int* temp = malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++) {
			if (A[j] < A[i])
				count++;
			else if (A[j] == A[i] && j < i)
				count++;
			temp[count] = A[i];
		}
	}

	memcpy(A, temp, n * sizeof(int));
	free(temp);
}

void count_sort_parallel(int* A, int n) {
	int i, j, count;
	int* temp = malloc(n * sizeof(int));

#pragma omp parallel for shared(A, n, temp) private(i, j, count)
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++) {
			if (A[j] < A[i])
				#pragma omp atomic
				count++;
			else if (A[j] == A[i] && j < i)
				#pragma omp atomic
				count++;
			temp[count] = A[i];
		}
	}

	memcpy(A, temp, n * sizeof(int));
	free(temp);
}

int compare(const void* p, const void* q)
{
	int x = *(const int*)p;
	int y = *(const int*)q;

	if (x < y) return -1;
	else if (x > y) return 1;
	return 0;
}

void Lab3()
{
	srand(time(NULL));
	int num_rands = 10000;
	double start_time;
	int* A = RandomList_Ints(num_rands);
	int* B = CopyList(A, num_rands);
	int* C = CopyList(A, num_rands);

	printf("Sorting with serial count sort...");
	start_time = omp_get_wtime();
	count_sort_serial(A, num_rands);
	printf("DONE! -- Sorted in %lf seconds.\n\nSorting with parallel count sort...",
		(omp_get_wtime() - start_time));
	start_time = omp_get_wtime();
	count_sort_parallel(B, num_rands);
	printf("DONE! -- Sorted in %lf seconds.\n\nSorting with C library qsort...",
		(omp_get_wtime() - start_time));
	start_time = omp_get_wtime();
	qsort(C, num_rands, sizeof(C), &compare);
	printf("DONE! -- Sorted in %lf seconds.\n\n***",
		(omp_get_wtime() - start_time));


	return;
}
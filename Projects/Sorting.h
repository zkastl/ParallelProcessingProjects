#pragma once

#ifdef _OPENMP
	#include <omp.h>
#endif

#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#include "ArrayUtils.h"

void Sort(void(*sort)(int*, int, int), int* list, int low, int high, BOOL print);
void SortingARandomList(); 
void BubbleSort(int* list, int start, int list_len); 
void Quicksort(int *A, int low, int high);
void QuicksortParallel(int *A, int low, int high, int num_threads);

/* https://github.com/eduardlopez/quicksort-parallel/blob/master/quicksort-omp.h */
void QSP_internal(int *A, int low, int high, int cutoff);
void Swap(int *a, int *b);
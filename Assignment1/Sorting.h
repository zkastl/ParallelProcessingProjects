#pragma once
void Sort(void(*sort)(int*, int, int), int* list, int low, int high, BOOL print);
void SortingARandomList(); 
void BubbleSort(int* list, int start, int list_len); 
 int Quicksort_Partition(int *A, int low, int high);
void Quicksort(int *A, int low, int high);
#pragma warning(disable: 4996)

#include <stdio.h>
#include "Quicksort.h"

int main()
{
	int list[20] = { 5, 6, 111, 456, 20,
					23, 3, 0, 4, 8,
					10, 11, 1, 6, 12,
					26, 40, 5, 18, 14 };
	int idx = 0;

	printf("Original list: ");
	for (idx = 0; idx < 20; idx++)
	{
		printf("%d ", list[idx]);
	}
	printf("\n");

	QuickSort(list, 0, 19);
	printf("Sorted List: ");
	for (idx = 0; idx < 20; idx++)
	{
		printf("%d ", list[idx]);
	}
	printf("\n");

	return 0;
}
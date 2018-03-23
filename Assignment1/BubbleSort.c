#include "ArrayUtils.h"
#include "BubbleSort.h"
#include "Defs.h"

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
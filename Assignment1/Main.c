#pragma warning(disable 4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void Swap(int *a, int *b);
int *Mtx_Multiply(int *mtx1, int *mtx2, int mtx_rows, int mtx1_cols, int mtx2_cols);
int Partition(int *A, int low, int high);
void QuickSort(int *A, int low, int high);


int main()
{
	int a = 5;
	int b = 6;
	printf("a is stored at %d, value is %d.\n", &a, a);
	printf("b is stored at %d, value is %d.\n", &b, b);
	printf("Swap values...\n");
	Swap(&a, &b);
	printf("a is now stored at %d, value is %d.\n", &a, a);
	printf("b is now stored at %d, value is %d.\n", &b, b);

	int list[20] = { 5, 6, 111, 456, 20,
					23, 3, 0, 4, 8,
					10, 11, 1, 6, 12,
					26, 40, 5, 18, 14 };

	printf("Original list: ");
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	QuickSort(list, 0, 20);
	printf("Sorted List: ");
	for (i = 0; i < 20; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	/*scanf(NULL);*/
	return 0;
}

/* { { 1, 2, 3 }, { 4, 5, 6 } }  --2x3 matrix*/
int *Mtx_Multiply(int *mtx1, int *mtx2, int mtx1_rows, int mtx1_cols, int mtx2_cols)
{
	int i,j = 0;
	int *product = (int*)malloc(mtx1_rows*mtx2_cols * sizeof(int));
	for (i = 0; i < mtx1_rows; i++)
	{
	}

	return NULL;
}

int Partition(int *A, int low, int high)
{
	int pivot = A[high];
	int small = low - 1;

	for (int j = low; j <= (high - 1); j++)
	{
		if (A[j] <= pivot)
		{
			small++;
			Swap(&A[small], &A[high]);
		}
	}
	Swap(&A[small + 1], &A[high]);
	return (small + 1);
}

void QuickSort(int *A, int low, int high)
{
	if (low < high)
	{
		int part = Partition(A, low, high);

		QuickSort(A, low, part - 1);
		QuickSort(A, part + 1, high);
	}
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
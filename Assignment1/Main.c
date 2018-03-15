#pragma warning(disable 4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void swap(int *a, int *b);
int *mtx_multiply(int *mtx1, int *mtx2, int mtx_rows, int mtx1_cols, int mtx2_cols);

int main()
{
	int a = 5;
	int b = 6;
	printf("a is stored at %d, value is %d.\n", &a, a);
	printf("b is stored at %d, value is %d.\n", &b, b);
	printf("Swap values...\n");
	swap(&a, &b);
	printf("a is now stored at %d, value is %d.\n", &a, a);
	printf("b is now stored at %d, value is %d.\n", &b, b);

	/*scanf(NULL);*/
	return 0;
}

/* { { 1, 2, 3 }, { 4, 5, 6 } }  --2x3 matrix*/
int *mtx_multiply(int *mtx1, int *mtx2, int mtx1_rows, int mtx1_cols, int mtx2_cols)
{
	int i,j = 0;
	int *product = (int*)malloc(mtx1_rows*mtx2_cols * sizeof(int));
	for (i = 0; i < mtx1_rows; i++)
	{
	}

	return NULL;
}

int *transpose(int *mtx1)
{
	return NULL;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
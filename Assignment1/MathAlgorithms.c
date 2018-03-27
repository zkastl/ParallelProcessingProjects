#include "MathAlgorithms.h"

unsigned long long* FibbonacciSequence(int num_fibs)
{
	if (num_fibs < 2) {
		printf("Not enough terms to generate a sequence; number of terms must be at least 2");
	}
	unsigned long long *fibs = (unsigned long long*)malloc(num_fibs * sizeof(unsigned long long));
	fibs[0] = 1;
	fibs[1] = 1;

	printf("First %d Fibbonacci numbers: %llu %llu ", num_fibs, fibs[0], fibs[1]);
	for (int i = 2; i < num_fibs; i++)
	{
		fibs[i] = fibs[i - 1] + fibs[i - 2];
		printf("%llu ", fibs[i]);
	}
	printf("\n");

	return fibs;
}
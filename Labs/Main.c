#include <stdlib.h>
#include <time.h>
#include "Lab1.h"

long double Pi_Estimation(unsigned long long number_of_tosses) {
	unsigned long long number_in_circle = 0;
	for (unsigned long long toss = 0; toss < number_of_tosses; toss++) {
		double random_value = 0.;
		srand(time(NULL));
		double x = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double y = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double distance_squared = x * x + y * y;
		if (distance_squared <= 1)
			number_in_circle++;
	}
	long double pi_estimate = 4. * (double) number_in_circle / (double) number_of_tosses;

	printf("%lf", pi_estimate);
	return pi_estimate;
}

//void count_sort_serial(int* A, int n) {
//	int i, j, count;
//	int* temp = malloc(n * sizeof(int));
//
//	for (i = 0; i < n; i++) {
//		count = 0;
//		for (j = 0; j < n; j++) {
//			if (A[j] < A[i])
//				count++;
//			else if (A[j] == A[i] && j < i)
//				count++;
//			temp[count] = A[i];
//		}
//
//		memcpy(A, temp, n * sizeof(int));
//		free(temp);
//	}
//}

int main() {
	
	Lab1(100000000);
	Pi_Estimation(18446744073709551615);
	return 0;
}
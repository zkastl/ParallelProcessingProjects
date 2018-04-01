#include <stdlib.h>
#include "Lab1.h"

//void Pi_estimation_prototype(int number_of_tosses) {
//	int number_in_circle = 0;
//	for (int toss = 0; toss < number_of_tosses; toss++) {
//		int x = 0; // random double between -1 and 1
//		int y = 0; // random double between -1 and 1
//		int distance_squared = x * x + y * y;
//		if (distance_squared <= 1)
//			number_in_circle++;
//	}
//	long double pi_estimate = 4 * number_in_circle / ((double)number_of_tosses);
//
//	return;
//}

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
	return 0;
}
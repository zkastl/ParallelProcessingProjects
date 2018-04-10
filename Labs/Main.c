#include "Lab1.h"
#include "Lab2.h"

#define NUM_THREADS 8

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
	
	Lab1(100000000, NUM_THREADS);
	Pi_Estimation_Parallel(1000000000, NUM_THREADS);
	return 0;
}
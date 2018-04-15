#include <stdio.h>
#include <math.h>
#include <omp.h>

#define THREAD_COUNT 4

void HomeworkProblem5_10(int n) {
#pragma omp parallel num_threads(THREAD_COUNT)
	{
		int i;
		double my_sum = 0.0;
		for (i = 0; i < n; i++) {
#pragma omp atomic
			my_sum += sin(i);
		}
	}
}
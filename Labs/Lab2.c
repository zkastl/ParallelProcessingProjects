#include "Lab2.h"

double Pi_Estimation(long long number_of_tosses) {
	long long number_in_circle = 0; 
	long long toss = 0;
	for (toss = 0; toss < number_of_tosses; toss++) {
		printf("Toss #%llu...\n", toss);
		double random_value = 0.;
		srand(time(NULL));
		double x = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double y = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double distance_squared = x * x + y * y;
		if (distance_squared <= 1)
			number_in_circle++;
	}
	long double pi_estimate = 4. * (double)number_in_circle / (double)number_of_tosses;

	printf("%lf", pi_estimate);
	return pi_estimate;
}

double Pi_Estimation_Parallel(long long number_of_tosses, int num_threads) {
	long long number_in_circle = 0;
	long long toss = 0;
#pragma omp parallel for num_threads(num_threads)
	for (toss = 0; toss < number_of_tosses; toss++) {
		//printf("Toss #%lld...\n", toss);
		double random_value = 0.;
		srand(time(NULL));
		double x = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double y = (double)rand() / RAND_MAX * 2.0 - 1.0; // random double between -1 and 1
		double distance_squared = x * x + y * y;
		if (distance_squared <= 1)
			number_in_circle++;
	}
	double pi_estimate = 4. * (double)number_in_circle / (double)number_of_tosses;

	printf("%lf", pi_estimate);
	return pi_estimate;
}
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

double Pi_Estimation(long long number_of_tosses);
double Pi_Estimation_Parallel(long long number_of_tosses, int num_threads);
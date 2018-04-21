#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

struct Histogram {
	int LessThanPoint1; 
	int LessThanPoint2;
	int LessThanPoint3;
	int LessThanPoint4;
	int LessThanPoint5;
	int LessThanPoint6;
	int LessThanPoint7;
	int LessThanPoint8;
	int LessThanPoint9;
	int LessThan1;
	int GreaterThan1;
	int LessThanZero;
} histogram;

/* Function to sort the values for an array of floats into the histogram structure
* This method is serial
*/
void SortArrayHistogramSerial(float* randVals, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (randVals[i] < 0)
			histogram.LessThanZero++;
		else if (randVals[i] < 0.1)
			histogram.LessThanPoint1++;
		else if (randVals[i] < 0.2)
			histogram.LessThanPoint2++;
		else if (randVals[i] < 0.3)
			histogram.LessThanPoint3++;
		else if (randVals[i] < 0.4)
			histogram.LessThanPoint4++;
		else if (randVals[i] < 0.5)
			histogram.LessThanPoint5++;
		else if (randVals[i] < 0.6)
			histogram.LessThanPoint6++;
		else if (randVals[i] < 0.7)
			histogram.LessThanPoint7++;
		else if (randVals[i] < 0.8)
			histogram.LessThanPoint8++;
		else if (randVals[i] < 0.9)
			histogram.LessThanPoint9++;
		else if (randVals[i] < 1.0)
			histogram.LessThan1++;
		else
			histogram.GreaterThan1++;
	}
}
/* Function to sort the values for an array of floats into the histogram structure
* This method is parallel -- only changes are pragma statements for omp
*/
void SortArrayHistogramParallel(float* randVals, int size, int num_threads)
{
	int i;
#pragma omp parallel for num_threads(4)
	for (i = 0; i < size; i++) {
		if (randVals[i] < 0)
			histogram.LessThanZero++;
		else if (randVals[i] < 0.1)
			histogram.LessThanPoint1++;
		else if (randVals[i] < 0.2)
			histogram.LessThanPoint2++;
		else if (randVals[i] < 0.3)
			histogram.LessThanPoint3++;
		else if (randVals[i] < 0.4)
			histogram.LessThanPoint4++;
		else if (randVals[i] < 0.5)
			histogram.LessThanPoint5++;
		else if (randVals[i] < 0.6)
			histogram.LessThanPoint6++;
		else if (randVals[i] < 0.7)
			histogram.LessThanPoint7++;
		else if (randVals[i] < 0.8)
			histogram.LessThanPoint8++;
		else if (randVals[i] < 0.9)
			histogram.LessThanPoint9++;
		else if (randVals[i] < 1.0)
			histogram.LessThan1++;
		else
			histogram.GreaterThan1++;
	}
}

float* RandomList_Floats(int numRands)
{
	/* Initialize values */
	time_t t;
	float a = 1.;
	srand((unsigned int)time(&t));
	float* list = (float*)malloc(numRands * sizeof(float));

	for (int idx = 0; idx < numRands; idx++) {
		list[idx] = (float)rand() / (float)(RAND_MAX / a);
	}

	return list;
}

void InitializeHistogram() {
	histogram.LessThanZero = 0;
	histogram.LessThanPoint1 = 0;
	histogram.LessThanPoint2 = 0;
	histogram.LessThanPoint3 = 0;
	histogram.LessThanPoint4 = 0;
	histogram.LessThanPoint5 = 0;
	histogram.LessThanPoint6 = 0;
	histogram.LessThanPoint7 = 0;
	histogram.LessThanPoint8 = 0;
	histogram.LessThanPoint9 = 0;
	histogram.LessThan1 = 0;
	histogram.GreaterThan1 = 0;
}

void PrintHistogram() {
	printf("-----------------\n");
	printf(" ...-0.0 -- |  %d\n", histogram.LessThanZero);
	printf(" 0.0-0.1 -- |  %d\n", histogram.LessThanPoint1);
	printf(" 0.1-0.2 -- |  %d\n", histogram.LessThanPoint2);
	printf(" 0.2-0.3 -- |  %d\n", histogram.LessThanPoint3);
	printf(" 0.3-0.4 -- |  %d\n", histogram.LessThanPoint4);
	printf(" 0.4-0.5 -- |  %d\n", histogram.LessThanPoint5);
	printf(" 0.5-0.6 -- |  %d\n", histogram.LessThanPoint6);
	printf(" 0.6-0.7 -- |  %d\n", histogram.LessThanPoint7);
	printf(" 0.7-0.8 -- |  %d\n", histogram.LessThanPoint8);
	printf(" 0.8-0.9 -- |  %d\n", histogram.LessThanPoint9);
	printf(" 0.9-1.0 -- |  %d\n", histogram.LessThan1);
	printf(" 1.0-... -- |  %d\n", histogram.GreaterThan1);
	printf("-----------------\n");
}

/* Driver Program for Lab 1 */
void Lab1(int numRands, int num_threads)
{
	// Create a random array of floats
	float* randomValues = RandomList_Floats(numRands);

	// Initialize the histogram to all zeroes
	InitializeHistogram();

	// Sort the numbers into the histogram using the serial method
	// Time the amount it takes, and print the histogram when finished
	double start_time = omp_get_wtime();
	SortArrayHistogramSerial(randomValues, numRands);
	printf("Time Elapsed (Serial) -- %lf\n", (omp_get_wtime() - start_time));
	PrintHistogram();

	printf("#############################\n");

	// Initialize the histogram to all zeroes
	InitializeHistogram();

	// Sort the numbers into the histogram using the parallel method
	// Time the amount it takes, and print the histogram when finished
	start_time = omp_get_wtime();
	SortArrayHistogramParallel(randomValues, numRands, num_threads);
	printf("Time Elapsed (Parallel) -- %lf\n", (omp_get_wtime() - start_time));
	PrintHistogram();

	free(randomValues);
}
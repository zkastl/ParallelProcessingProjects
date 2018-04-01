#pragma once
#include <stdio.h>

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

void InitializeHistogram();
void PrintHistogram();
void Lab1(int numRands);
float* RandomList();
void SortArrayHistogramSerial(float* randVals, int size);
void SortArrayHistogramParallel(float* randVals, int size);

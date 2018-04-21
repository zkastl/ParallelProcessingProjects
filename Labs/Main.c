#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"

#define NUM_THREADS 8



int main() {

	Lab1(1000000, NUM_THREADS);
	Lab2(NUM_THREADS);
	Lab3();
	return 0;
}
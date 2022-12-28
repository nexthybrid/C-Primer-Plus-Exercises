// C Primer Plus
// Chapter 10 Exercise 08:

// Use a copy function from Programming Exercise 2 to copy the third through
// fifth elements of a seven-element array into a three-element array. The
// function itself need not be altered; just choose the right actual arguments.
// (The actual arguments need not be an array name and array size. They only
// have to be the address of an array element and a number of elements to be
// processed.)

#include <stdio.h>
#include <stdlib.h>	// RAND_MAX, NULL
#include <time.h>	// srand, time, rand
#define COPY_SIZE 3

void copyArray_arrayNotation(double * target, const double * source, int length)
{
	for (int i = 0; i < length; i++){
		target[i] = source[i];
	}
}

void copyArray_pointerNotation(double * target, const double * source, const int length)
{
	for (int i = 0; i < length; i++)
		*(target + i) = *(source + i);
}

// moving both a copy of the source pointer, and the target pointer
void copyArray_pointerNotation_2(double * target, const double *sourceStart, const double *sourceEnd)
{
	for (const double * p = sourceStart; p <= sourceEnd; p++, target++)
		*target = *p;
}

void printArray(const double *array, const int length)
{
	for (int i = 0; i < length; i++)
		printf("%lf\t", array[i]);
	printf("\n");
}

int main()
{
	printf("Generating a random array of size 7:\n");
	double array[7];
	srand(time(NULL));
	for (int i = 0; i < 7; i++){
		array[i] = rand() / (double) RAND_MAX;
		printf("%.3lf  ", array[i]);
	}
	// copy to a smaller array of size 3
	double target[3];
	// copyArray_arrayNotation(target, (array + 2), 3);
	// copyArray_pointerNotation(target, (array + 2), 3); // alternative 1
	copyArray_pointerNotation_2(target, (array + 2), (array + 4)); // alternative 2
	printf("\nThe 3rd through 5th element of the first array is copied to a second array:\n");
	printArray(target, 3);
	return 0;
}


// #include <stdio.h>

// void copy_ptrs(double *target, double *source_start, double *source_end);

// int main(void)
// {
// 	double source[7] = {2.4, 5.9, 7.8, 1.5, 3.3, 5.3, 6.8};
// 	double target[3];

// 	copy_ptrs(target, source + 2, source + 5);

// 	// print arrays
// 	for (int i = 0; i < 7; i++)
// 		printf("%.1f ", source[i]);
// 	putchar('\n');

// 	for (int i = 0; i < 3; i++)
// 		printf("%.1f ", target[i]);
// 	putchar('\n');

// 	return 0;
// }

// void copy_ptrs(double *target, double *source_start, double *source_end)
// {
// 	// copy arr using pointer notation and pointer endpoint

// 	for (double *ptr = source_start; ptr < source_end; ptr++, target++)
// 		*target = *ptr;
// }
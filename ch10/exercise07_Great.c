// C Primer Plus
// Chapter 10 Exercise 7:

// Write a program that initializes a two-dimensional array-of-double and uses
// one of the copy functions from exercise 2 to copy it to a second two
// dimensional array. (Because a two-dimensional array is an array of arrays, a
// one-dimensional copy function can be used with each subarray.)

/* KNOWLEDGE LEARNED FROM THIS EXERCISE
	pointer to a 2-dimensional array can be interpreted differentily:
	double array[2][5];
	1. array, the name of the 2-d array, is interpreted as a pointer 
		of type double (*<pname>)[5].
	2. array[1], the 1-d array notation of the array name, is interpreted as a pointer 
		of type double *<pname>.
	3. array + 1, using pointer math, is interpreted as moving the pointer
		of type double (*<pname>)[5] forward one position.
	4. array[1] + 1, using pointer math, is interpreted as moving the pointer
		of type double *<pname> forward one position.
	5. When passed into a function as parameter, the name of a 2-dimensional array
		represents whatever the formal prameter notation indicates. For example,
		if the parameter is specified as double *<pname>, then the name is interpreted
		as a pointer of type double *<pname>. On the contrary, if the parameter is
		specified as double (*<pname>)[5], then the name is interpreted as a pointer
		of type double (*<pname>)[5]. Sometimes, we want to use the pointer arithmatic
		on the name for one pointer type, but then we want to use the name to perform
		other tasks for another pointer type (see the implementation of copy_2d_array
		below). In such cases, we need to be flexible, use the name for one type, then
		use the name for another type by casting it into another pointer type.
*/

#include <stdio.h>
#include <time.h>	// srand, time, rand
#include <stdlib.h>	// RAND_MAX
#define N1_ARR 2
#define N2_ARR 5

void copy_2d_array(double (*target)[N2_ARR], double (*source)[N2_ARR], int size_1, int size_2);
void copyArray_pointerNotation(double * target, double * source, const int length);

int main()
{
	double array[N1_ARR][N2_ARR];
	double target[N1_ARR][N2_ARR];
	double temp;
	printf("Generating a random %d x %d array of double:\n", N1_ARR, N2_ARR);
	srand(time(NULL));
	for (int i = 0; i < N1_ARR; i++){
		for (int j = 0; j < N2_ARR; j++){
			temp = rand() / (double)RAND_MAX;
			array[i][j] = temp;
			printf("%.3lf  ", temp);
		}
		printf("\n");
	}
	copy_2d_array(target, array, N1_ARR, N2_ARR);
	printf("Copied the array to a new array. The new array:\n");
	for (int i = 0; i < N1_ARR; i++){
		for (int j = 0; j < N2_ARR; j++){
			printf("%.3lf  ", target[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void copyArray_pointerNotation(double *target, double *source, const int length)
{
	for (int i = 0; i < length; i++)
		*(target + i) = *(source + i);
}

void copy_2d_array(double (*target)[N2_ARR], double (*source)[N2_ARR], int size_1, int size_2)
{
	// here, target and source are of type double (*)[N2_ARR]
	for (int i = 0; i < size_1; i++){
		// casting the pointer into 1D array form after locating.
		copyArray_pointerNotation((double *)(target + i), (double *)(source + i), size_2);
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// void copy_ptr(double *target, double *source, int arr_len);
// void print_row(double (*arr)[10], int row);

// int main(void)
// {
// 	// copy one 10 by 10 array to another 10 by 10 array

// 	double source[10][10];
// 	double target[10][10];

// 	// initialize source array
// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			source[i][j] = rand() / (double) RAND_MAX;

// 	// copy source array to target
// 	for (int i = 0; i < 10; i++)
// 		copy_ptr(target[i], source[i], 10);

// 	// print arrays
// 	printf("%-50s", "Source");
// 	printf("   ");
// 	printf("%-50s", "Target");
// 	putchar('\n');
// 	for (int i = 0; i < 103; i++)
// 		putchar('-');
// 	putchar('\n');
// 	for (int i = 0; i < 10; i++)
// 	{
// 		print_row(source, i);
// 		printf("   ");
// 		print_row(target, i);
// 		putchar('\n');
// 	}

// 	return 0;
// }

// void copy_ptr(double *target, double *source, int arr_len)
// {
// 	// copy array using pointer notation

// 	for (int i = 0; i < arr_len; i++)
// 	{
// 		*(target + i) = *(source + i);
// 	}
// }

// void print_row(double (*arr)[10], int row)
// {
// 	// print a row from a n by 10 array of doubles

// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%.2f ", arr[row][i]);
// 	}
// }
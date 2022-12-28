// C Primer Plus
// Chapter 10 Exercise 10:

// Write a function that sets each element in an array to the sum of the
// corresponding elements in two other arrays. That is, if array 1 has the
// values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6, the
// function assigns array 3 the values 3, 4, 9, and 14. The function should
// take three array names and an array size as arguments. Test the function in
// a simple program.

/* Using VLA functions for array operations */

#include <stdio.h>
#include <stdlib.h>		// RAND_MAX, NULL
#include <time.h>		// srand, time, rand

void print_array_VLA(int dim1, int arr[dim1]);
void sum_two_arrays_VLA(int dim1, int target[dim1], int source1[dim1], int source2[dim1]);

int main()
{
	printf("Provide an array length:\n");
	int length;
	scanf("%d", &length);
	while (getchar() != '\n')
		continue;	// clean up stdin buffer
	printf("Generating two arrays of size %d.\n");
	srand(time(NULL));
	int arr1[length], arr2[length], arr3[length];
	for (int i = 0; i < length; i++){
		arr1[i] = rand();
		arr2[i] = rand();
	}
	printf("The two arrays are:\n");
	print_array_VLA(length, arr1);
	print_array_VLA(length, arr2);
	printf("Now summing the two arrays into a third array:\n");
	sum_two_arrays_VLA(length, arr3, arr1, arr2);
	print_array_VLA(length, arr3);
	return 0;
}

void print_array_VLA(int dim1, int arr[dim1])
{
	for (int i = 0; i < dim1; i++)
		printf("%d  ", arr[i]);
	printf("\n");	
}

void sum_two_arrays_VLA(int dim1, int target[dim1], int source1[dim1], int source2[dim1])
{
	for (int i = 0; i < dim1; i++)
		target[i] = source1[i] + source2[i];
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define SIZE 10

// void add_arrays(int *addend1, int *addend2, int *sum, int array_length);

// int main(void)
// {
// 	// test add_arrays

// 	srand(time(NULL));

// 	int array1[SIZE];
// 	int array2[SIZE];
// 	int sum[SIZE];

// 	// initialize arrays with random ints
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		array1[i] = rand() % 20;
// 		array2[i] = rand() % 20;
// 	}

// 	// get sum of arrays
// 	add_arrays(array1, array2, sum, SIZE);

// 	// print arrays
// 	printf("%8s %8s %8s\n", "Array 1", "Array 2", "Sum");
// 	for (int i = 0; i < SIZE; i++)
// 		printf("%8d %8d %8d\n", array1[i], array2[i], sum[i]);

// 	return 0;
// }

// void add_arrays(int *addend1, int *addend2, int *sum, int array_length)
// {
// 	// calculate elementwise sum of two arrays

// 	for (int *tar = sum; tar < sum + array_length; tar++, addend1++, addend2++)
// 		*tar = *addend1 + *addend2;
// }
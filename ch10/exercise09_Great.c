// C Primer Plus
// Chapter 10 Exercise 9:

// Write a program that initializes a two-dimensional 3×5 array-of-double and
// uses a VLA- based function to copy it to a second two-dimensional array.
// Also provide a VLA-based function to display the contents of the two arrays.
// The two functions should be capable, in general, of processing arbitrary N×M
// arrays. (If you don’t have access to a VLA-capable compiler, use the
// traditional C approach of functions that can process an N×5 array).

/* USE OF VLA
	VLA allows defining the size of arrays as previous integer variables.
	In this context, it can also be used in function calls. In the function header,
	the function parameter list needs to follow the right order. The size integers
	definition need to precede the VLA array or VLA pointer definition.
*/

/* USE OF MULTI-DIM ARRAY POINTER
	In C, multi-dimensional arrays (mostly 2d arraus) are represented by pointers
	of type column-sized-numericals, where numericals can be int, double, etc.
	The function header syntax for such types is: double (*<pname>)[col_size].
*/

#include <stdio.h>
#include <stdlib.h>	// RAND_MAX, NULL
#include <time.h>	// srand, time, rand

void copyArray_pointerNotation(double *target, double *source, const int length);
// NOTE: int size_1 and int size_2 has to be declared on the LEFT of 
// the other two parameters who depend on them.
void copy_2d_array_VLA(int size_1, int size_2, double (*target)[size_2], double (*source)[size_2]);

int main()
{
	printf("Provide the dimensions of the 2D array:\n");
	int N1, N2;
	while (scanf("%d %d", &N1, &N2) != 2){
		printf("Please provide two positive integers:\n");
		while (getchar() != '\n')	// buffer clean up
			continue;
	}
	printf("Generating a random %d x %d array of double:\n", N1, N2);
	double array[N1][N2];	// VLA
	srand(time(NULL));
	for (int i =0; i < N1; i++){
		for (int j = 0; j < N2; j++){
			array[i][j] = rand() / (double)RAND_MAX;
			printf("%.3lf  ", array[i][j]);
		}
		printf("\n");
	}
	// copy VLA to a second VLA (array size fixed at this point)
	double target[N1][N2];
	copy_2d_array_VLA(N1, N2, target, array);
	printf("Copied the VLA array to a new VLA array. The new array:\n");
	for (int i = 0; i < N1; i++){
		for (int j = 0; j < N2; j++){
			printf("%.3lf  ", target[i][j]);
		}
		printf("\n");
	}
}

void copyArray_pointerNotation(double *target, double *source, const int length)
{
	for (int i = 0; i < length; i++)
		*(target + i) = *(source + i);
}

// the hardcore alternative: VLA + pointer-indexing
void copy_2d_array_VLA(int size_1, int size_2,double (*target)[size_2], double (*source)[size_2])
{
	// here, target and source are of type double (*)[N2_ARR]
	for (int i = 0; i < size_1; i++){
		// casting the pointer into 1D array form after locating using 2D array form.
		copyArray_pointerNotation((double *)(target + i),
			(double *)(source + i), size_2);
	}
}

// #include <stdio.h>
// #define ROWS 3
// #define COLUMNS 5

// void copy_2dim_arr(int rows, int cols, double source[rows][cols],
// 	               double target[rows][cols]);
// void print_2dim_arr(int rows, int cols, double arr[rows][cols]);

// int main(void)
// {
// 	double array1[ROWS][COLUMNS] = {{4.3, 5.7, 2.1, 6.6, .8},
// 						            {5.6, 23.5, 73.2, 12.3, 123},
// 						            {22.1, 35.3, 6.35, 0.132, 11.1}};
// 	double array2[ROWS][COLUMNS];

// 	// copy array1 to array2
// 	copy_2dim_arr(ROWS, COLUMNS, array1, array2);

// 	// print contents of arrays
// 	printf("Array 1:\n");
// 	print_2dim_arr(ROWS, COLUMNS, array1);
// 	putchar('\n');

// 	printf("Array2:\n");
// 	print_2dim_arr(ROWS, COLUMNS, array2);

// 	return 0;
// }

// void copy_2dim_arr(int rows, int cols, double source[rows][cols],
// 	               double target[rows][cols])
// {
// 	// copy one two-dimensional array to another

// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; j++)
// 		{
// 			target[i][j] = source[i][j];
// 		}
// 	}
// }

// void print_2dim_arr(int rows, int cols, double arr[rows][cols])
// {
// 	// print the contents of a two-dimensional array

// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; j++)
// 			printf(" %10.3f ", arr[i][j]);

// 		putchar('\n');
// 	}
// }

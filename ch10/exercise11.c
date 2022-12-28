// C Primer Plus
// Chapter 10 Exercise 11:

// Write a program that declares a 3×5 array of int and initializes it to some
// values of your choice. Have the program print the values, double all the
// values, and then display the new values. Write a function to do the
// displaying and a second function to do the doubling. Have the functions take
// the array name and the number of rows as arguments.

/* This question has a problem: if a function only knows the number of rows, and 
	not the number of columns in an array, it is impossible to work with that array.
*/

#include <stdio.h>
#include <stdlib.h>	// srand, rand, NULL
#include <time.h>	// time
#define N1 3
#define N2 5

int main()
{
	printf("Generating a random 3x5 array of int:\n");
	int array[N1][N2];
	srand(time(NULL));
	for (int i = 0; i < N1; i++){
		for (int j = 0; j < N2; j++){
			array[i][j] = rand();
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}
	// double_array(array,N1);	// without number of columns it is impossible to operate on 2d arrays
	return 0;
}

// #include <stdio.h>

// void print_Nx5_int_array(int (*array)[5], int rows);
// void double_Nx5_int_array(int (*array)[5], int rows);

// int main(void)
// {
// 	int array[3][5] = {{ 2,  5,  6,  9,  1},
// 					   {23,  1,  5, 66, 54},
// 					   { 9, 73, 23, 39,  2}};

// 	printf("Original array:\n");
// 	print_Nx5_int_array(array, 3);

// 	// double array and print new values
// 	double_Nx5_int_array(array, 3);
// 	printf("Doubled array:\n");
// 	print_Nx5_int_array(array, 3);

// 	return 0;
// }

// void print_Nx5_int_array(int (*array)[5], int rows)
// {
// 	// print the contents of an N x 5 array of ints

// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < 5; ++j)
// 		{
// 			printf(" %5d ", array[i][j]);
// 		}
// 		putchar('\n');
// 	}
// }

// void double_Nx5_int_array(int (*array)[5], int rows)
// {
// 	// double the elements of an N x 5 array of ints

// 	for (int i = 0; i < rows; ++i)
// 		for (int j = 0; j < 5; j++)
// 			array[i][j] *= 2;
// }
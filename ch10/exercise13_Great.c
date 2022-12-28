// C Primer Plus
// Chapter 10 Exercise 13:

// Write a program that prompts the user to enter three sets of five double
// numbers each. (You may assume the user responds correctly and doesn’t enter
// non-numeric data.) The program should accomplish all of the following:
// a. Store the information in a 3×5 array.
// b. Compute the average of each set of five values.
// c. Compute the average of all the values.
// d. Determine the largest value of the 15 values.
// e. Report the results.
// Each major task should be handled by a separate function using the
// traditional C approach to handling arrays. Accomplish task “b” by using a
// function that computes and returns the average of a one-dimensional array;
// use a loop to call this function three times. The other tasks should take
// the entire array as an argument, and the functions performing tasks “c” and
// “d” should return the answer to the calling program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N1 3
#define N2 5

/* user also has option to automatically generate the 3x5 array with a prompt.*/

/* KNOWLEDGE: ABOUT GETCHAR()
	if you use getchar() in an if-else condition, DO NOT repeat the getchar()
	after the first call, otherwise you will get a next character, which is likely
	'\n'..
*/

void get_3x5_from_user(double array[N1][N2]);
void print_1d_array(int dim1, double *array);
void print_2d_array_VLA(int dim1, int dim2, double array[dim1][dim2]);
void compute_row_average_VLA(double * average, int dim1, int dim2, double array[dim1][dim2]);
double compute_1d_array_average_VLA(int dim1, double * array);
double compute_2d_array_largest_VLA(int dim1, int dim2, double array[dim1][dim2]);

int main()
{
	printf("Manually type the 3x5 array? (y/n):\n");
	char ch;
	double array[N1][N2];
	if ((ch = getchar()) == 'y'){	
		while (getchar() != '\n')
			continue;
		get_3x5_from_user(array);
	} else if (ch == 'n'){			// !!! do not getchar() again here
		srand(time(NULL));
		for (int i = 0; i < N1; i++)
			for (int j = 0; j < N2; j++)
				array[i][j] = rand() / (double)RAND_MAX;
	}
	printf("The array is:\n");
	print_2d_array_VLA(N1, N2, array);
	printf("The average of each row is:\n");
	double average[N1];
	compute_row_average_VLA(average, N1, N2, array);
	print_1d_array(N1, average);
	printf("The average of all values is: %.3f.\n", compute_1d_array_average_VLA(N1,average));
	printf("The largest value of all values is: %.3f.\n",
		compute_2d_array_largest_VLA(N1, N2, array));
	return 0;
}

void get_3x5_from_user(double array[N1][N2])
{
	printf("Please enter 3x5 double numbers, separate each row by hitting the Enter key:\n");
	for (int i = 0; i < N1; i++){
		for (int j = 0; j < N2; j++){
			scanf("%lf", &array[i][j]);
		}
	}
}

void print_2d_array_VLA(int dim1, int dim2, double array[dim1][dim2])
{
	for (int i = 0; i < dim1; i++){
		for (int j = 0; j < dim2; j ++){
			printf("%.3lf  ", array[i][j]);
		}
		printf("\n");
	}
}

void print_1d_array(int dim1, double *array)
{
	for (int i = 0; i < dim1; i++)
		printf("%.3lf  ", *(array + i));
	printf("\n");
}

// compute average value of each row
void compute_row_average_VLA(double * average, int dim1, int dim2, double array[dim1][dim2])
{
	double sum;
	for (int i = 0; i < dim1; i++){
		sum = 0;	// resest sum
		for (int j = 0; j < dim2; j++){
			sum += array[i][j];
		}
		average[i] = sum / (double)dim2;
	}
}

double compute_1d_array_average_VLA(int dim1, double * array)
{
	double sum = 0;
	for (int i = 0; i < dim1; i++)
		sum += array[i];
	return sum / (double)dim1;
}

double compute_2d_array_largest_VLA(int dim1, int dim2, double array[dim1][dim2])
{
	double max = array[0][0];
	double temp;
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2; j++)
			if ((temp = array[i][j]) > max)
				max = temp;
	return max;
}

// #include <stdio.h>
// #define ROWS 3
// #define COLUMNS 5

// double compute_row_average(double array[COLUMNS]);
// double compute_array_average(double (*array)[COLUMNS], int rows);
// double largest_value(double (*array)[COLUMNS], int rows);

// int main(void)
// {
// 	double data[ROWS][COLUMNS];

// 	for (int i = 0; i < ROWS; i++)
// 	{
// 		printf("Enter set of %d doubles: ", COLUMNS);
// 		for (int j = 0; j < COLUMNS; j++)
// 		{
// 			scanf("%lf", data[i] + j);
// 		}
// 	}

// 	// print row averages
// 	printf("Row Averages:\n");
// 	for (int i = 0; i < ROWS; i++)
// 	{
// 		printf("\tAverage for row %d: %.3f\n", i + 1, compute_row_average(data[i]));
// 	}

// 	// print array average
// 	printf("Average for entire array: %.3f\n", compute_array_average(data, ROWS));

// 	// print largest value
// 	printf("Maximum array value: %.3f\n", largest_value(data, ROWS));

// 	return 0;
// }

// double compute_row_average(double array[COLUMNS])
// {
// 	double total = 0;
// 	for (int i = 0; i < COLUMNS; i++)
// 		total += array[i];

// 	return total / COLUMNS;
// }

// double compute_array_average(double (*array)[COLUMNS], int rows)
// {
// 	double total = 0;
// 	for (int i = 0; i < rows; i++)
// 		for (int j = 0; j < COLUMNS; j++)
// 			total += array[i][j];

// 	return total / (rows * COLUMNS);
// }

// double largest_value(double (*array)[COLUMNS], int rows)
// {
// 	double max = array[0][0];
// 	for (int i = 0; i < rows; i++)
// 		for (int j = 0; j < COLUMNS; j++)
// 			if (array[i][j] > max)
// 				max = array[i][j];

// 	return max;
// }
// C Primer Plus
// Chapter 10 Exercise 6:

// Write a function that reverses the contents of an array of double and test
// it in a simple program.

#include <stdio.h>
#include <time.h>	// srand, time, rand
#include <stdlib.h>	// RAND_MAX
#define N_ARR 20

void reverse_array(double * arr, int size);
void print_array(double * arr, int size);

int main()
{
	double array[N_ARR];
	srand(time(NULL));	// set rand seed
	printf("Generating a random array of size %d:\n", N_ARR);
	for (int i = 0; i < N_ARR; i++){
		array[i] = rand() / (double) RAND_MAX;
		printf("%.3lf  ", array[i]);
	}
	reverse_array(array, N_ARR);
	printf("\n\nAfter reverse_array() call, the new array is:\n");
	print_array(array, N_ARR);

}

// reverse the order of the array using pair-wise swap
void reverse_array(double *arr, int size)
{
	double temp;
	for (int i = 0; i < size / 2; i++){
		// swap arr[i] with arr[size-i-1]
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}

void print_array(double *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%.3lf  ", arr[i]);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>


// void reverse_array(double *arr, int arr_size);

// int main(void)
// {
// 	// test reverse_array()

// 	printf("Testing reverse_array()\n");

// 	double test1[9];
// 	double test2[10];
// 	double test3[2];

// 	srand(time(NULL));

// 	// initialize test array 1 with 9 random doubles
// 	for (int i = 0; i < 9; i++)
// 		test1[i] = rand() / (double) RAND_MAX;

// 	// initialize test array 2 with 10 random doubles
// 	for (int i = 0; i < 10; i++)
// 		test2[i] = rand() / (double) RAND_MAX;

// 	// initialize test array 1 with 2 random doubles
// 	for (int i = 0; i < 2; i++)
// 		test3[i] = rand() / (double) RAND_MAX;

// 	// test array 1

// 	printf("First Test\n");
// 	// print original array
// 	printf("%10s: ", "Original");
// 	for (int i = 0; i < 9; i++)
// 		printf("%5.2f ", test1[i]);
// 	putchar('\n');

// 	//print reversed array
// 	reverse_array(test1, 9);
// 	printf("%10s: ", "Reversed");
// 	for (int i = 0; i < 9; i++)
// 		printf("%5.2f ", test1[i]);
// 	putchar('\n');

// 	// test array 2

// 	printf("Second Test\n");
// 	// print original array
// 	printf("%10s: ", "Original");
// 	for (int i = 0; i < 10; i++)
// 		printf("%5.2f ", test2[i]);
// 	putchar('\n');

// 	//print reversed array
// 	reverse_array(test2, 10);
// 	printf("%10s: ", "Reversed");
// 	for (int i = 0; i < 10; i++)
// 		printf("%5.2f ", test2[i]);
// 	putchar('\n');

// 	// test array 3

// 	printf("Third Test\n");
// 	// print original array
// 	printf("%10s: ", "Original");
// 	for (int i = 0; i < 2; i++)
// 		printf("%5.2f ", test3[i]);
// 	putchar('\n');

// 	//print reversed array
// 	reverse_array(test3, 2);
// 	printf("%10s: ", "Reversed");
// 	for (int i = 0; i < 2; i++)
// 		printf("%5.2f ", test3[i]);
// 	putchar('\n');

// 	return 0;
// }

// void reverse_array(double *arr, int arr_size)
// {
// 	// reverse an array of double

// 	double tmp;

// 	for (int i = 0; i < arr_size / 2; i++)
// 	{
// 		// swap values between indexes i and (arr_size - 1 - i)
// 		tmp = arr[i];
// 		arr[i] = arr[arr_size - 1 - i];
// 		arr[arr_size - 1 - i] = tmp;
// 	}
// }
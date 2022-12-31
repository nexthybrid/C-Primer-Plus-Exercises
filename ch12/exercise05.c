// C Primer Plus
// Chapter 12 Exercise 5:

// Write a program that generates a list of 100 random numbers in the range
// 1–10 in sorted decreasing order. (You can adapt the sorting algorithm from
// Chapter 11, “Character Strings and String Functions,” to type int. In this
// case, just sort the numbers themselves.)

#include <stdio.h>
#include <stdlib.h>	// srand, rand, RAND_MAX, NULL
#include <time.h>	// time
#define N 100

void sortedRand_VLA(int dim1, int array[dim1]);
void print_1d_array_VLA(int dim1, int array[dim1]);

int main()
{
	// generate a random list of 100 numbers sorted
	int array[N];
	sortedRand_VLA(N, array);
	print_1d_array_VLA(N, array);
	return 0;
}

int flipOnce_VLA(int dim1, int array[dim1])
{
	int flipCount = 0;
	int temp;
	for (int i = 0; i < dim1 - 1; i++){
		if (array[i] < array[i + 1]){
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			flipCount++;
		}
	}
	return flipCount;
}

void bubbleSort_VLA(int dim1, int array[dim1])
{
	// continue flipping until flip count goes to zero
	int flipCount;
	do {
		flipCount = flipOnce_VLA(dim1, array);
	} while (flipCount > 0);
}

// sortRand_VLA: assign a sorted random array between 1-10 to array
void sortedRand_VLA(int dim1, int array[dim1])
{
	// step 1 generate a random array
	srand(time(NULL));
	for (int i = 0; i < dim1; i++){
		array[i] = rand() % 10 + 1;
	}
	// step 2 sorte the random array
	bubbleSort_VLA(dim1, array);
}

void print_1d_array_VLA(int dim1, int array[dim1])
{
	for (int i = 0; i < dim1; i++){
		printf("%d  ", array[i]);
	}
	printf("\n");
}

// #include <stdio.h>
// #include <stdlib.h>

// void random_ints(int *int_array);

// int main(void)
// {
// 	// test random ints
// 	int int_array[100];
// 	random_ints(int_array);

// 	for (int i = 0; i < 100; i++)
// 	{
// 		printf("%2d ", int_array[i]);
// 		if (i % 20 == 19)
// 			putchar('\n');
// 	}

// 	putchar('\n');
// 	return 0;
// }

// void random_ints(int *int_array)
// {
// 	int tmp;

// 	// initialize array
// 	for (int i = 0; i < 100; i++)
// 		int_array[i] = rand() % 10 + 1;
	
// 	// sort array in decreasing order
// 	for (int i = 0; i < 99; i++)
// 		for (int j = i + 1; j < 100; j++)
// 		{
// 			if (int_array[i] < int_array[j])
// 			{
// 				tmp = int_array[i];
// 				int_array[i] = int_array[j];
// 				int_array[j] = tmp;
// 			}
// 		}
// }
// C Primer Plus
// Chapter 10 Exercise 3:

// Write a function that returns the largest value stored in an array-of-int.
// Test the function in a simple program.

#include <stdio.h>
#include <ctype.h>
#define N_MAX 20

int largest(const int *arr, int size);
int max_int(int *arr, int arr_size);
void printArray(int *arr, int size);
void copy_array(int *arrCopy, const int *arrSource, int size);
int bubble_descend(int *arr, int size);

int main()
{
	int array[N_MAX];
	int nextInt;
	int inputCount;
	char ch;
	printf("Provide an integer array (less than 20 elements, separated by space, end by .):\n");
	while (scanf("%d ", &nextInt) == 1){
		array[inputCount++] = nextInt;
	}
	printf("The array you provided is:\n");
	printArray(array,inputCount);
	printf("The largest number in the array is %d.\n", max_int(array, inputCount));
}

// using bubble method (time O(n^2), space O(1))
// buble sort is ONLY good when sequential access is much faster than random access.
int largest(const int *arr, int size)
{
	int arrCopy[N_MAX];
	copy_array(arrCopy, arr, size);
	int swapCount = 0;
	do{
		swapCount = bubble_descend(arrCopy, size);
	} while (swapCount != 0);
	return arrCopy[0];
}

// for-loop max finding (time fixed O(n), space O(1))
int max_int(int *arr, int arr_size)
{
	int max = arr[0];
	for (int i = 1; i < arr_size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void copy_array(int *arrCopy, const int *arrSource, int size)
{
	for (int i = 0; i < size; i++)
		arrCopy[i] = arrSource[i];
}

// perform one pass of bubbling in the descending order
int bubble_descend(int *arr, int size)
{
	int temp;
	int swapCount = 0;
	for (int i = 0; i < size - 1; i++){
		if (arr[i] < arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			swapCount++;
		}
	}
	return swapCount;
}

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define SIZE 10

// int max_int(int *arr, int arr_size); // function prototype

// int main(void)
// {
// 	int test[SIZE];

// 	srand(time(NULL)); // seed random number generator
	
// 	// initialize test array with random ints between 0 and 99
// 	for (int i = 0; i < SIZE; i++)
// 		test[i] = rand() % 100;

// 	printf("The maximum of ");
// 	for (int i = 0; i < SIZE; i++)
// 		printf("%d ", test[i]);
// 	printf("is: %d\n", max_int(test, SIZE));

// 	return 0;
// }

// int max_int(int *arr, int arr_size)
// {
// 	int max = arr[0];
// 	for (int i = 1; i < arr_size; i++)
// 	{
// 		if (arr[i] > max)
// 			max = arr[i];
// 	}

// 	return max;
// }

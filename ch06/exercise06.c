// C Primer Plus
// Chapter 6 Exercise 6:
// Write a program that prints a table with each line giving an integer, its
// square, and its cube. Ask the user to input the lower and upper limits for the
// table. Use a for loop.

#include <stdio.h>

int main()
{
	printf("Enter a lower and upper limit for integers:\n");
	int a;
	int b;
	scanf("%i %i", &a, &b);
	printf("Integer\t\tSquare\t\tCube\n");
	for (int i = a; i <= b; i++){
		printf("%i\t\t%i\t\t%i\n", i, i * i, i * i * i);
	}
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	long upper = -1, lower=0;
// 	int reads;

// 	printf("This program prints a table of integers with their "
// 		   "squares and cubes.\n");
// 	do
// 	{	
// 		printf("Enter lower and upper integer limits (in that order): ");
// 		reads = scanf("%ld%ld", &lower, &upper);
// 		if (reads != 2)
// 		{
// 			while (getchar() != '\n') ; // if read fails, clear input buffer
// 		}
// 	} while (lower > upper); // if lower is greater than upper, get new input

// 	printf("\n");
// 	// table header
// 	printf(" Integer       | Square        | Cube          \n");
// 	printf("---------------|---------------|---------------\n");
// 	for (long int i = lower; i <= upper; i++)
// 	{
// 		printf(" %-14ld| %-14ld| %-14ld\n", i, i * i, i * i * i);		
// 	}
// 	printf("\n");

// 	return 0;
// }

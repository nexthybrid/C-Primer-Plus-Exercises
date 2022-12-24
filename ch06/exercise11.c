// C Primer Plus
// Chapter 6 Exercise 11:

// Write a program that reads eight integers into an array and then prints them in
// reverse order.

#include <stdio.h>

int main()
{
	printf("Enter eight integers:\n");
	int a[8];
	scanf("%i %i %i %i %i %i %i %i"
			,&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]);
	for (int i = 7; i >= 0; i--)
		printf("%i\t", a[i]);
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	int int_array[8];
// 	int i; // array index

// 	printf("Enter 8 integers:\n");
// 	for (i = 0; i < 8; i++) // read ints into array
// 	{
// 		scanf("%d", &int_array[i]);
// 	}
// 	for (i--; i >= 0; i--) // decrement i to 7 to initialize loop
// 	{
// 		printf("%d", int_array[i]);
// 	}
// 	printf("\n");

// 	return 0;
// }

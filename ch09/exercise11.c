// C Primer Plus
// Chapter 9 Exercise 11:

// Write and test a Fibonacci() function that uses a loop instead of recursion
// to calculate Fibonacci numbers.

#include <stdio.h>

unsigned int Fibonacci(unsigned int n)
{
	unsigned int left = 1;
	unsigned int right = 1;
	unsigned int res = 0;
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else {
		for (int i = 3; i <= n; i++){
			res = left + right;
			left = right;	// update
			right = res;	// update
		}
		return res;
	}
}

int main()
{
	unsigned int n;
	printf("Enter a positive integer:\n");
	while (scanf("%u", &n) == 1){
		while (getchar() != '\n')
			continue;
		if (n == 0){
			printf("Fibonacci number for 0 is not defined.\n");
		} else {
			printf("The Fibonacci number for %u is %u.\n", n, Fibonacci(n));
		}
		printf("\nEnter a positive integer:\n");
	}
	return 0;
}


// #include <stdio.h>	

// long Fibonacci(long n);

// int main(void) {
// 	long n;

// 	printf("Test Fibonacci() function\n");
// 	printf("Enter an integer n: ");

// 	while (scanf("%ld", &n) == 1)
// 	{
// 		printf("Fibonacci #%ld = %ld\n", n, Fibonacci(n));

// 		printf("Enter an integer n: ");
// 	}

// 	return 0;
// }

// long Fibonacci(long n)
// {
// 	// return nth Fibonacci number

// 	// handle invalid arguments
// 	if (n < 1)
// 	{
// 		printf("Error: n must be a positive integer.\n");
// 		return -1;
// 	}

// 	long fib_n1 = 0, fib_n = 1, fib_n2;

// 	// n equals 1 or 2
// 	if (n == 1) return 0;
// 	if (n == 2) return 1;

// 	// n greater than or equal to 3
// 	for (long i = 3; i <= n; i++)
// 	{
// 		// update old values
// 		fib_n2 = fib_n1;
// 		fib_n1 = fib_n;
// 		fib_n = fib_n1 + fib_n2;
// 	}

// 	return fib_n;
// }
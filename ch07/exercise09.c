// C Primer Plus
// Chapter 7 Exercise 09:

// Write a program that accepts a positive integer as input and then displays
// all the prime numbers smaller than or equal to that number.

#include <stdio.h>
#include <stdlib.h>	// malloc
#include <math.h>	// sqrt
#include <stdbool.h>	// bool

void printPrimes(const unsigned int limit)
{
	// dynamic memory allocation
	unsigned int nMax;
	bool isPrime = true;
	unsigned int * foundP = (unsigned int *)malloc(limit/2 * sizeof(unsigned int));
	int countP = 2;
	foundP[0] = 2;
	foundP[1] = 3;
	for (int i = 5; i <= limit; i = i + 2){
		// first try all the existing primes below sqrt(i)
		isPrime = true;	// reset
		unsigned int nMax = (int)sqrt(i);
		int j = 0;
		while (foundP[++j] <= nMax && isPrime){
			if (i % foundP[j] == 0){
				isPrime = false;
			}
		}
		if (isPrime){
			printf("%d\t", i);
			foundP[countP++] = i;
		}
	}
	free(foundP);
	foundP = NULL;
}

int main()
{
	printf("Enter an upper limit for integer:\n");
	unsigned int limit;
	scanf("%u", &limit);
	printPrimes(limit);
	return 0;
}

// #include <stdio.h>
// #include <stdbool.h>

// void flush_input_buffer(void);

// int main(void)
// {
// 	bool prime_flag;
// 	int limit;
// 	printf("Primes: this program prints all primes less than or equal to any positive integer.\n");
// 	printf("Enter a positive integer: \n");
// 	while (scanf("%d", &limit) != 1 || limit < 1)
// 	{
// 		flush_input_buffer();
// 		printf("Enter a positive integer: \n");
// 	}

// 	for (int i = 2; i <= limit; i++)
// 	{
// 		prime_flag = true;
// 		for (int j = 2; j < i; j++) // for all j less than i ...
// 		{
// 			if (i % j == 0) // if i is divisible by j ...
// 			{
// 				prime_flag = false; // then i is not prime
// 				break; // break out of inner loop
// 			}
// 		}
// 		if (prime_flag)
// 			printf("%d is prime.\n", i);
// 	}

// 	return 0;
// }

// void flush_input_buffer(void)
// {
// 	while (getchar() != '\n')
// 		;
// }

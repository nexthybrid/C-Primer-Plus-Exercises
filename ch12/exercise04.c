// C Primer Plus
// Chapter 12 Exercise 4:

// Write and test in a loop a function that returns the number of times it has
// been called.

#include <stdio.h>

int a_function();

int main()
{
	printf("Loop how many times? ");
	int nLoop;
	scanf("%d", &nLoop);
	while (getchar() != '\n')
		continue;
	int i = 0;
	while (i++ < nLoop){
		printf("a_function() has bee called %d times,\n", a_function());
	}
	return 0;
}

int a_function()
{
	static int count = 0;	// this is a declaration + initialization line
							// so it would not be executed over and over but once.
	return ++count;
}

// #include <stdio.h>

// unsigned int counter(void);

// int main(void)
// {
// 	// test counter()
// 	int iterations = 0;
// 	printf("How many times do you want to call counter()? ");
// 	scanf("%d", &iterations);
// 	for (int i = 0; i < iterations; i++)
// 		printf("counter() returns %u\n", counter());

// 	return 0;
// }

// unsigned int counter(void)
// {
// 	static unsigned int call_count = 0;
// 	return ++call_count;
// }
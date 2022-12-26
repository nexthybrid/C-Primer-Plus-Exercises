// C Primer Plus
// Chapter 9 Exercise 4:

// The harmonic mean of two numbers is obtained by taking the inverses of the
// two numbers, averaging them, and taking the inverse of the result. Write a
// function that takes two double arguments and returns the harmonic mean of
// the two numbers.

#include <stdio.h>

double harmonic_mean(double a, double b)
{
	return 1 / (0.5 * (1 / a + 1 / b));
}

int main()
{
	double a, b, c;
	int nAssigned;
	printf("Enter two numbers:\n");
	while ((nAssigned = scanf("%lf %lf", &a, &b)) == 2){
		while (getchar() != '\n')	// clean buffer
			continue;
		while ((a == 0 || b == 0) || nAssigned != 2){
			printf("The input cannot be zero. Enter two numbers:\n");
			nAssigned = scanf("%lf %lf", &a, &b);
			while (getchar() != '\n')	// clean buffer
				continue;
		}
		c = harmonic_mean(a, b);
		printf("The harmonic mean of %.3lf and %.3lf is %.3lf\n",
			a, b, c);
		printf("\nEnter two numbers:\n");
	}
	return 0;
}

// #include <stdio.h>

// double harmonic_mean(double, double);

// int main(void)
// {
// 	double x, y;

// 	printf("Harmonic means\n");
// 	printf("Enter two numbers: ");
// 	while (scanf("%lf %lf", &x, &y) == 2)
// 	{
// 		printf("%f\n", harmonic_mean(x, y));

// 		printf("Enter two numbers: ");
// 	}

// 	return 0;
// }

// double harmonic_mean(double x, double y)
// {
// 	return 2 / (1 / x + 1 / y);
// }
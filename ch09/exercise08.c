// C Primer Plus
// Chapter 9 Exercise 8

// Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
// function that returned the result of raising a type double number to a
// positive integer value. Improve the function so that it correctly handles
// negative powers. Also, build into the function that 0 to any power other
// than 0 is 0 and that any number to the 0 power is 1. (It should report that
// 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop. Test
// the function in a program.

#include <stdio.h>

double calcPower(const double, const int);
double basicPower(const double, const unsigned int);

int main()
{
	printf("Enter a type double number and a non-negative integer:\n");
	double a;
	int b;
	double res;
	while (scanf("%lf %i", &a, &b) == 2){
		while (getchar() != '\n')
			continue;
		res = calcPower(a, b);
		printf("%.3lf raised to the power of %i is %.3lf.\n", a, b, res);
		printf("\nEnter a type double number and a non-negative integer:\n");
	}
	return 0;
}

// advanced power calculation, b can be any integer
double calcPower(const double a, const int b)
{
	if (b < 0)
		return 1.0 / basicPower(a, -b);
	else if (b > 0)
		return basicPower(a, b);
	else{	// b == 0
		if (a == 0)
			printf("0 to the power of 0 is not defined, returning value 1 instead.\n");
		return 1;
	}
}

// basic power calculation, b is a positive integer
double basicPower(const double a, const unsigned int b)
{
	double res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	return res;
}

// #include <stdio.h>
// #include <stdlib.h> // prototype for abs() 

// double power(double base, int exponent);

// int main(void)
// {
// 	double base, output;
// 	int exponent;

// 	printf("Test power() function:\n");
// 	printf("Enter a :double: base and :int: exponent: ");
// 	while (scanf("%lf %d", &base, &exponent) == 2)
// 	{
// 		output = power(base, exponent);

// 		printf("%f ^ %d = %f \n", base, exponent, output);

// 		printf("Enter a :double: base and :int: exponent: ");
// 	}

// 	return 0;
// }

// double power(double base, int exponent)
// {
// 	double power = base;

// 	if (base == 0)
// 	{
// 		if (exponent == 0)
// 		{
// 			printf("Warning: 0 ^ 0 is undefined. Using 1.\n");
// 			return 1.0;
// 		}
// 		else
// 			return 0;
// 	}

// 	for (int i = 1; i < abs(exponent); i++)
// 	{
// 		power *= base;
// 	}

// 	if (exponent < 0)
// 		power = 1 / power;

// 	return power;
// }
// C Primer Plus
// Chapter 9 Exercise 8

// Redo Programming Exercise 8, but this time use a recursive function.

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

// (recursive function) basic power calculation, b is a positive integer
double basicPower(const double a, const unsigned int b)
{
	if (b > 1)
		return a * basicPower(a, b - 1);
	else
		return a;
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
// 	double dbl_power;

// 	// handle powers of zero
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

// 	if (exponent == 0) return 1; // stop recursion

// 	dbl_power = base * power(base, abs(exponent) - 1); // recursion step

// 	// if exponent is negative, take reciprocal
// 	if (exponent < 0) dbl_power = 1 / dbl_power;

// 	return dbl_power;
// }
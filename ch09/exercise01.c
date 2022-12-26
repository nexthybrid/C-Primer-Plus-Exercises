// C Primer Plus
// Chapter 9 Exercise 1:

// Devise a function called min(x,y) that returns the smaller of two double
// values. Test the function with a simple driver.

/* Knowledge: According to C Primer Listing 9.3, a DRIVER is just another 
	name for a while-looped test program for a certain function.
*/

#include <stdio.h>

double min(double x, double y)
{
	return x < y ? x : y;
}

int main()
{
	printf("Provide two double values:\n");
	double x, y;
	while (scanf("%lf %lf", &x, &y) == 2){
		printf("The minimum between %.3lf and %.3lf is %.3lf.\n",
			x, y, min(x,y));
		printf("Provide two double values:\n");
	}
	return 0;
}

// #include <stdio.h>

// double min(double, double);

// int main(void)
// {
// 	double x, y;

// 	printf("Enter two doubles (non-double input to quit): ");
// 	while (scanf("%lf %lf", &x, &y) == 2)
// 	{
// 		printf("The minimum of %.3f and %.3f is %.3f.\n", x, y, min(x,y));
// 		printf("Enter two doubles (non-double input to quit): ");
// 	}

// 	return 0;
// }

// double min(double x, double y)
// {
// 	// return the minimum of x and y
// 	return x < y ? x : y;
// }
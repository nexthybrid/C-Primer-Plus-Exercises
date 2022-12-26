// C Primer Plus
// Chapter 9 Exercise 6:

// Write and test a function that takes the addresses of three double variables
// as arguments and that moves the value of the smallest variable into the
// first variable, the middle value to the second variable, and the largest
// value into the third variable.

#include <stdio.h>

void sort_ascend(double *, double *, double *);
void swap(double *, double *);
int bubble_ascend(double *, double *, double *);

int main()
{
	double a, b, c;
	printf("Enter three doubles:\n");
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3){
		while (getchar() != '\n')
			continue;
		sort_ascend(&a, &b, &c);
		printf("After call to sort_ascend(), the values are:\n");
		printf("%.3lf %.3lf %.3lf\n", a, b, c);
		printf("\nEnter three doubles:\n");
	}
}

void sort_ascend(double * a, double * b, double * c)
{
	/*using the famous Bubble sort:
		swap neighboring values if not ascending;
		after one pass, rinse and repeat, until:
		no swap counts during one entire pass.
	*/
	int swapCount = 0;
	do {
		swapCount = bubble_ascend(a, b, c);
	} while (swapCount > 0);
}

// perform one pass of bubble sort with ascending order
// return the number of swaps
int bubble_ascend(double * a, double * b, double * c)
{
	int swaps = 0;
	if (*a > *b){
		swap(a, b);
		swaps++;
	}
	if (*b > *c){
		swap(b, c);
		swaps++;
	}
	return swaps;
}

void swap(double *a, double *b)
{
	double temp;
	if (*a > *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

// #include <stdio.h>

// void sort_variables(double *x, double *y, double *z);

// int main(void)
// {
// 	double x, y, z;

// 	printf("Test sort_variables():\n");
// 	printf("Enter three numbers x, y and z:\n");
// 	while(scanf("%lf %lf %lf", &x, &y, &z) == 3)
// 	{
// 		putchar('\n');
// 		printf("Before calling sort_variables:\n");
// 		printf("x = %f, y = %f, z = %f\n", x, y, z);

// 		sort_variables(&x, &y, &z);

// 		putchar('\n');
// 		printf("After calling sort_variables:\n");
// 		printf("x = %f, y = %f, z = %f\n", x, y, z);

// 		putchar('\n');

// 		printf("Enter three numbers x, y and z:\n");
// 	}

// 	return 0;
// }

// void sort_variables(double *x, double *y, double *z)
// {
// 	double tmp;

// 	if (*x > *y)
// 	{
// 		// switch x and y
// 		tmp = *y;
// 		*y = *x;
// 		*x = tmp;
// 	}

// 	if (*y > *z)
// 	{
// 		// switch y and z
// 		tmp = *z;
// 		*z = *y;
// 		*y = tmp;

// 		if (*x > *y)
// 		{
// 			// switch x and y
// 			tmp = *y;
// 			*y = *x;
// 			*x = tmp;
// 		}
// 	}
// }

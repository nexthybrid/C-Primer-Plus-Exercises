// C Primer Plus
// Chapter 7 Exercise 3:

// Write a program that reads integers until 0 is entered. After input
// terminates, the program should report the total number of even integers
// (excluding the 0) entered, the average value of the even integers, the total
// number of odd integers entered, and the average value of the odd integers.

#include <stdio.h>
#define STOP 0

int main()
{
	int a;
	int nOdd = 0;
	int nEven = 0;
	float sumOdd = 0;
	float sumEven = 0;
	printf("Enter integers (terminate with the integer 0):\n");
	// scanf will discard any leading whitespace for %d (but not for %c)
	while ((scanf("%d", &a) == 1) && a != STOP){
		if (a % 2){
			nOdd += 1;
			sumOdd += a;
		} else if (a % 2 == 0) {
			nEven += 1;
			sumEven += a;
		}
	}
	float avgOdd = sumOdd / nOdd;
	float avgEven = sumEven / nEven;
	printf("Total # of odd integers: %i\n", nOdd);
	printf("Average of odd integers: %f\n", avgOdd);
	printf("Total # of even integers: %i\n", nEven);
	printf("Average of even integers: %f\n", avgEven);
	return 0;
}

// #include <stdio.h>
// #include <ctype.h>

// #define STOP 0

// int main(void)
// {
// 	int even_count = 0, even_sum = 0, odd_count = 0, odd_sum = 0;
// 	float even_avg, odd_avg;
// 	int input;

// 	printf("Enter integers (0 to stop):\n");
// 	while(scanf("%d", &input) == 1 && input != STOP)
// 	{
// 		if (input % 2 == 0)
// 		{
// 			even_count++;
// 			even_sum += input;
// 		}
// 		else
// 		{
// 			odd_count++;
// 			odd_sum += input;
// 		}
// 	}

// 	even_avg = even_sum / (float) even_count;
// 	odd_avg = odd_sum / (float) odd_count;

// 	printf("Number of even integers: %d\n", even_count);
// 	printf("Average value of even integers: %.2f\n", even_avg);
// 	printf("Number of odd integers: %d\n", odd_count);
// 	printf("Average value of odd integers: %.2f\n", odd_avg);

// 	return 0;
// }

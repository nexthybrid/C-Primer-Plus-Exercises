/* C Primer Plus

Chapter 5 Exercise 3:

Write a program that asks the user to enter the number of days and then converts
that value to weeks and days. For example, it would convert 18 days to 2 weeks,
4 days. Display results in the following format:

18 days are 2 weeks, 4 days.

Use a while loop to allow the user to repeatedly enter day values; terminate the
loop when the user enters a nonpositive value, such as 0 or -20. */

#include <stdio.h>
#define DAYS_IN_A_WEEK 7

int main()
{
	printf("Please provide a number of days:\n");
	unsigned int days;
	scanf("%u", &days);
	while (days > 0){
		unsigned int weeks = days / DAYS_IN_A_WEEK;
		printf("%u days are %u weeks, %u days.\n\n", days, weeks, days % DAYS_IN_A_WEEK);
		printf("Please provide a number of days:\n");
		scanf("%u", &days);
	}

	return 0;
}


// #include <stdio.h>

// const int DAYS_PER_WEEK = 7;

// int main(void)
// {
// 	int days;

// 	printf("Enter a number of days (or enter 0 to quit): ");
// 	scanf("%d", &days);
// 	while (days > 0)
// 	{
// 		printf("%d days are %d weeks, %d days.\n", days, days / DAYS_PER_WEEK,
// 		       days % DAYS_PER_WEEK);

// 		printf("Enter a number of days (or enter 0 to quit): ");
// 		scanf("%d", &days);
// 	}

// 	return 0;
// }

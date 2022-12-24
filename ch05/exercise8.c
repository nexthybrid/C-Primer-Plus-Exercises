// C Primer Plus

// Chapter 5 Exercise 8:

// Write a program that displays the results of applying the modulus operation. The
// user should first enter an integer to be used as the second operand, which will
// then remain unchanged. Then the user enters the numbers for which the modulus
// will be computed, terminating the process by entering 0 or less. A sample run
// should look like this:

//     > This program computes moduli.
//     > Enter an integer to serve as the second operand: 256
//     > Now enter the first operand: 438
//     > 438 % 256 is 182
//     > Enter next number for first operand (<= 0 to quit): 1234567
//     > 1234567 % 256 is 135
//     > Enter next number for first operand (<= 0 to quit): 0
//     > Done

#include <stdio.h>

void Temperatures(float temp_F)
{
	printf("The temperature in Fahrenheit is: %.2f\n", temp_F);
	float temp_C = (temp_F - 32) * 0.5556;
	printf("The temperature in Celsius is: %.2f\n", temp_C);
	float temp_K = temp_C + 273.16;
	printf("The temperature in Kelvin is: %.2f\n", temp_K);
}

int main()
{
	printf("Provide a temperature in Fahrenheit:____\b\b\b\b");
	float temp_F;
	scanf("%f", &temp_F);
	Temperatures(temp_F);
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	int first, second;
// 	printf("This program computes moduli.\n");
// 	printf("Enter an integer to serve as the second operand: ");
// 	scanf("%d", &second);
// 	printf("Now enter the first operand: ");
// 	scanf("%d", &first);
// 	while (first > 0)
// 	{
// 		printf("%d %% %d is %d\n", first, second, first % second); //print results

// 		printf("Enter next number for first operand (<= 0 to quit): ");
// 		scanf("%d", &first); // get new input
// 	}

// 	return 0;
// }

// C Primer Plus
// Chapter 7 Exercise 4

// Using if else statements, write a program that reads input up to #, replaces
// each period with an exclamation mark, replaces each exclamation mark
// initially present with two exclamation marks, and reports at the end the
// number of substitutions it has made.

#include <stdio.h>
#define STOP '#'

int main()
{
	printf("Enter whatever and end with #:\n");
	int ch;
	int nComma = 0;
	int nExclam = 0;
	while ((ch = getchar()) != STOP){
		switch(ch){
			case ',':
				nComma += 1;
				printf("!");
				break;
			case '!':
				nExclam += 1;
				printf("!!");
				break;
			default:
				printf("%c", ch);
		}
	}
	printf("\n\nStatistics:\n");
	printf("Commas replaced: %d\n", nComma);
	printf("Exclamations replaced: %d\n", nExclam);
	return 0;
}

// #include <stdio.h>

// #define STOP '#'

// int main(void)
// {
// 	char ch;

// 	printf("Enter input (%c to exit):\n", STOP);
// 	while ((ch = getchar()) != STOP)
// 	{
// 		if (ch == '.')
// 			printf("!");
// 		else if (ch == '!')
// 			printf("!!");
// 		else
// 			printf("%c", ch);
// 	}

// 	return 0;
// }

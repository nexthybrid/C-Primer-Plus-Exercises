// C Primer Plus

// Chapter 6 Exercise 4:

// Use nested loops to produce the following pattern:
// A
// BC
// DEF
// GHIJ
// KLMNO
// PQRSTU

#include <stdio.h>

int main()
{
	printf("Please enter an upper case letter:\n");
	char lastChar;
	scanf("%c", &lastChar);
	// print pyramid using for loop
	int length = lastChar - 'A' + 1;
	// printf("length = %i\n", length);
	// (length-1) is also the position for the center character in 0-indexing
	for (int i = 0; i < length; i++){
		// on the ith line, we print (length-1-i) spaces before starting the characters
		for (int j = 0; j < 2*length-1; j++){
			if (j < length-1-i || j > length-1+i)
				printf(" ");
			else
				printf("%c", (j < length? ('A'+j - (length-i) + 1) : ('A'-j + 2*length-2 - (length-i) + 1)));
		}
		printf("\n");
	}

	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = 'A';

// 	for (int i = 1; i < 7; i++)
// 	{
// 		for(int j = 1; j <= i; j++)
// 		{
// 			printf("%c", c++); // print and THEN increment c
// 		}
// 		printf("\n");
// 	}

// 	return 0;
// }

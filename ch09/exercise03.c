// C Primer Plus
// Chapter 9 Exercise 3

// Write a function that takes three arguments: a character and two integers.
// The character is to be printed. The first integer specifies the number of
// times that the character is to be printed on a line, and the second integer
// specifies the number of lines that are to be printed. Write a program that
// makes use of this function.

#include <stdio.h>

void the_function(char, int, int);

int main()
{
	char ch;
	unsigned int i, j;
	printf("Provide a character, and two integers:\n");
	while (scanf("%c %d %d", &ch, &i, &j) == 3){
		while (getchar() != '\n')	// ALWAYS remember to clean buffer
			continue;				// especially if you scanf!
		the_function(ch, i, j);
		printf("\nProvide a character, and two integers:\n");
	}
	return 0;
}

void the_function(char ch, int a, int b)
{
	int i, j;
	for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			printf("%c", ch);
		}
		printf("\n");
	}
}

// #include <stdio.h>

// void printgrid(char ch, unsigned int cols, unsigned int rows);

// int main(void)
// {
// 	char ch;
// 	unsigned int rows, cols;

// 	printf("Enter a character, number of rows and number of columns: ");
// 	while (scanf("%c %u %u", &ch, &rows, &cols) == 3)
// 	{
// 		printgrid(ch, cols, rows);
// 		printf("Enter a character, number of rows and number of columns: ");
// 	}

// 	return 0;
// }

// void printgrid(char ch, unsigned int cols, unsigned int rows)
// {
// 	// prints given character in a block sized rows x cols
// 	for (unsigned int i = 0; i < rows; i++)
// 	{
// 		for (unsigned int j = 0; j < cols; j++)
// 		{
// 			putchar(ch);
// 		}
// 		putchar('\n');
// 	}
// }
// C Primer Plus
// Chapter 8 Exercise 6:

// Modify the get_first() function of Listing 8.8 so that it returns the first
// non- whitespace character encountered. Test it in a simple program.

/* menuette.c -- menu techniques */
#include <stdio.h>
#include <ctype.h>	// isspace()

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void)
{
int choice;
	void count(void);
	while ( (choice = get_choice()) != 'q')
	{
	switch (choice)
	{
		case 'a' : printf("Buy low, sell high.\n");
		break;
		case 'b' : putchar('\a'); /* ANSI */
		break;
		case 'c' : count();
		break;
		default : printf("Program error!\n");
		break;
	}
	}
	printf("Bye.\n");
	return 0;
}
void count(void)
{
	int n,i;
	printf("Count how far? Enter an integer:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
	printf("%d\n", i);
	while ( getchar() != '\n')
	continue;
}

char get_choice(void)	
{
	int ch;
	printf("Enter the letter of your choice:\n");
	printf("a. advice b. bell\n");
	printf("c. count q. quit\n");
	ch = get_first();
	while ( (ch < 'a' || ch > 'c') && ch != 'q')
	{
	printf("Please respond with a, b, c, or q.\n");
	ch = get_first();
	}
	return ch;
}

char get_first(void) // MODIFIED TO SKIP LEADING WHITESPACE
{
	int ch;
	// ch = getchar();
	while (isspace(ch = getchar()))
		continue;
	while (getchar() != '\n')	// buffer leftover cleanup
		continue;
	return ch;
}

int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
		putchar(ch); // dispose of bad input
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178, or 3: ");
	}
	return input;
}


// #include <stdio.h>
// #include <ctype.h>

// int get_first(void);

// int main(void)
// {
// 	int ch;

// 	printf("Test program for get_first():\n");
// 	printf("Enter a line; you should see the first non-whitespace\n");
// 	printf("character echoed in the terminal:\n");

// 	ch = get_first();
// 	printf("%c\n", ch);

// 	return 0;
// }

// int get_first(void)
// {
// 	// returns first non-whitespace character and clears
// 	// remaining input until next line break or EOF

// 	int ch, garbage;

// 	do {
// 		ch = getchar();
// 	}
// 	while (isspace(ch));
		

// 	while((garbage = getchar()) != '\n' && garbage != EOF)
// 		;

// 	return ch;
// }
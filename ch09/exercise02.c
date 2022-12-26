// C Primer Plus
// Chapter 9 Exercise 2:

// Devise a function chline(ch,i,j) that prints the requested character in
// columns i through j. Test it in a simple driver.


#include <stdio.h>

// print the character ch on one line, from column i to j.
void chline(char ch, unsigned int i, unsigned int j)
{
	int col;
	for (col = 0; col < i; col++){
		putchar(' ');	// does putchar also put down a \n?
	}
	for (; col < j; col ++)
		putchar(ch);
}

int main()
{
	char ch;
	unsigned int i, j;
	printf("Provide a character, and two integers:\n");
	while (scanf("%c %d %d", &ch, &i, &j) == 3){
		while (getchar() != '\n')
			continue;
		chline(ch, i, j);
		printf("\nProvide a character, and two integers:\n");
	}
	return 0;
}


// #include <stdio.h>

// void chline(char, unsigned int, unsigned int);

// int main(void)
// {
// 	char ch;
// 	unsigned int i, j;

// 	printf("Enter a character and two integers: ");
// 	while (scanf("%c %u %u", &ch, &i, &j) == 3)
// 	{
// 		chline(ch, i, j);
// 		printf("\n");

// 		while (getchar() != '\n') continue; // clear input
		
// 		printf("Enter a character and two integers: ");
// 	}

// 	return 0;
// }

// void chline(char ch, unsigned int i, unsigned int j)
// {
// 	unsigned int col;
// 	for (col = 1; col < i; col++)
// 	{
// 		putchar(' ');
// 	}

// 	for (; col <= j; col++)
// 	{
// 		putchar(ch);
// 	}
// }
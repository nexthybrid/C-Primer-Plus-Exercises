// C Primer Plus
// Chapter 8 Exercise 1:

// Devise a program that counts the number of characters in its input up to the
// end of file.

#include <stdio.h>

/* Ctrl + Z is the keyboard input for ending file.
*/

int main()
{
	char ch;
	int count = 0;
	while ((ch = getchar()) != EOF){
		count++;
	}
	printf("Total characters: %d\n", count);
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	int count = 0;

// 	while (getchar() != EOF)
// 	{
// 		count++;
// 	}
// 	printf("Character count: %d\n", count);

// 	return 0;
// }
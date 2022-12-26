// C Primer Plus
// Chapter 9 Exercise 7:

// Write a program that reads characters from the standard input to
// end-of-file. For each character, have the program report whether it is a
// letter. If it is a letter, also report its numerical location in the
// alphabet. For example, c and C would both be letter 3. Incorporate a
// function that takes a character as an argument and returns the numerical
// location if the character is a letter and that returns –1 otherwise.

#include <stdio.h>
#include <ctype.h>

int locateChar(char ch);

int main()
{
	char ch;
	int alphIdx;
	while ((ch = getchar()) != EOF){
		if (isalpha(ch)){
			alphIdx = locateChar(ch);
			printf("%c(%d)", ch, alphIdx);
		} else {
			printf("%c", ch);
		}
	}
	return 0;
}

// returns the numerical location in the alphabet (e.g., B = 2)
int locateChar(char ch)
{
	if (isalpha(ch)){
		if (islower(ch))
			return ch - 'a' + 1;
		else
			return ch - 'A' + 1;
	} else
		return -1;

}

// #include <stdio.h>
// #include <ctype.h>

// int letter_location(char ch);

// int main(void)
// {
// 	char ch;
// 	int location;

// 	while ((ch = getchar()) != EOF)
// 	{
// 		if ((location = letter_location(ch)) == -1)
// 			printf("%c is not a letter\n", ch);
// 		else
// 			printf("%c is a letter: location = %d\n", ch, location);
// 	} 

// 	return 0;
// }

// int letter_location(char ch)
// {
// 	if (isalpha(ch))
// 	{
// 		ch = tolower(ch);
// 		return (ch - 'a' + 1);
// 	}
// 	else
// 		return -1;
// }
// C Primer Plus
// Chapter 8 Exercise 05:

// Modify the guessing program of Listing 8.4 so that it uses a more
// intelligent guessing strategy. For example, have the program initially guess
// 50, and have it ask the user whether the guess is high, low, or correct. If,
// say, the guess is low, have the next guess be halfway between 50 and 100,
// that is, 75. If that guess is high, let the next guess be halfway between 75
// and 50, and so on. Using this binary search strategy, the program quickly
// zeros in on the correct answer, at least if the user does not cheat.

/* KNOWLEDGE FROM THIS EXAMPLE:
	During a while loop, getchar() and scanf() can fight
	with each other for grabbing inputs from the stream.

	The mechanism:

*/

/* KNOWLEDGE FROM THIS EXAMPLE:
	scanf() (when using "%c" as the format string) can accidentally consume
	whitespace characters (' ', \n, \t, \r) left over in the buffer stdin.
	This can often cause unintended algorithmic errors. Some suggests ridding
	scanf() once and for all. But if scanf() is to be used, then this potential
	whitespace leftover in the buffer problem must be properly addressed.
	
	One option is to use a buffer cleanup function to always clean up the buffer
	of any remaining garbage including the \n character. Another quick and dirty
	option (not recommended) is to add a space before %c in the format string:
		scanf(" %c", &ch);
	What this does is that it tells scanf() to deliberately skip whitespace
	characters that are leading in the buffer before reading in the character
	for assignment to ch.

	For doubling safety, you can combine the two options above.
*/

/* guess.c -- an inefficient and faulty number-guesser */
#include <stdio.h>
#include <stdbool.h>	// bool

int higherBound = 100;	// global variables for nextGuess
int lowerBound = 1;

int nextGuess(int prevGuess, bool isHigher)
{
	/*if the feedback is that truth isHigher, then the program
	takes the mid point between prevGuess and higherBound. Otherwise,
	take the mid point between prevGuess and lowerBound.*/
	int newGuess;
	if (isHigher){
		newGuess = (prevGuess + higherBound) / 2;	// integer divide will truncate
	} else {
		newGuess = (prevGuess + lowerBound) / 2;
	}
	return newGuess;
}

void cleanBuffer()
{
	while (getchar() != '\n')
		continue;
}

int main(void)
{
	int guess = 50;
	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\nan n if it is wrong.\n");
	printf("Uh...is your number %d?\n", guess);
	bool isHigher = false;
	char answerToGuess;
	char answerToHigher;
	scanf(" %c",&answerToGuess);
	cleanBuffer();
	while (answerToGuess != 'y'){
		answerToHigher = ' ';	// reset user answer
		do {
			printf("Okay, is your number higher than my guess? (y/n)\n");
			scanf(" %c", &answerToHigher);	// using " %c" in combination with cleanBuffer
			cleanBuffer();					// for double safety
		} while (answerToHigher != 'y' && answerToHigher != 'n');
		if (answerToHigher == 'y'){
			isHigher = true;
			lowerBound = guess;	// update lower bound
		}
		else if (answerToHigher == 'n'){
			isHigher = false;
			higherBound = guess;
		}
		printf("Well, then, is it %d?\n", guess = nextGuess(guess, isHigher));
		scanf(" %c",&answerToGuess);
		cleanBuffer();
	}
	printf("I knew I could do it!\n");
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	// initial search parameters
// 	int upper_bound = 100;
// 	int lower_bound = 0;
// 	int guess = 50;

// 	char ch;

// 	printf("Pick an integer from 1 to 100. I will try to guess ");
// 	printf("it.\nRespond with a y if my guess is right, with a h if it's");
// 	printf("\ntoo high and an l if it's too low.\n");
// 	printf("Uh...is your number %d?\n", guess);

// 	while ((ch = getchar()) != 'y')
// 	{
// 		while (getchar() != '\n') // clear input stream
// 			;
// 		if (ch == 'h')
// 			upper_bound = guess;
// 		else if (ch == 'l')
// 			lower_bound = guess;
// 		else
// 		{
// 			printf("Invalid valid input. Try again.\n");
// 			continue;
// 		}
// 		guess = (upper_bound + lower_bound) / 2.0;
// 		printf("Well, then, is it %d?\n", guess);
// 	}

// 	printf("I knew I could do it!\n");
// 	return 0;
// }
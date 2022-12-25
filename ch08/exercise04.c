// C Primer Plus
// Chapter 8 Exercise 4:

// Write a program that reads input as a stream of characters until
// encountering EOF. Have it report the average number of letters per word.
// Don’t count whitespace as being letters in a word. Actually, punctuation
// shouldn’t be counted either, but don’t worry about that now. (If you do want
// to worry about it, consider using the ispunct() function from the ctype.h
// family.)

#include <stdio.h>
#include <stdbool.h>	// bool
#define C_MIN 'A'	// minimum character
#define C_MAX 'z'	// maximum character 

/* TIP:
	can also use <ctype.h> and isalpha() to check if char is alphabetical
*/

int main()
{
	char ch;
	int charsInWords = 0;	// total number of chars in all words counted
	int wordSeparators = 0;	// total number of word separators (space, punctuation, etc)
	bool isPrevWordChar = false;	// whether the previous char is part of a word
	while ((ch = getchar()) != EOF){
		if (isPrevWordChar){	// previous char is a word-char
			if (ch < C_MIN || ch > C_MAX){
				isPrevWordChar = false;	// udpate
				wordSeparators  += 1;
			} else {
				charsInWords += 1;
			}
		} else {				// previous char is a non-word-char
			if (ch < C_MIN || ch > C_MAX){
				// nothing to update
			} else {
				isPrevWordChar = true;	// update
				charsInWords += 1;
			}
		}
	}
	// determine if the last char is a word-char or non-word-char
	// assuming the first character(s) in the stream is not a word separator
	int nWords;
	if (isPrevWordChar){
		nWords = wordSeparators - 1;
	} else {
		nWords = wordSeparators;
	}
	float avgCharInWords = (float)charsInWords / nWords;
	printf("Statistics:\n");
	printf("Total number words: %d\n", nWords);
	printf("Total number of characters in words: %d\n", charsInWords);
	printf("Average number of characters in words: %.2f\n", avgCharInWords);
	return 0;
}

// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>

// int main(void)
// {
// 	int ch;
// 	bool in_word = false;
// 	int letter_count = 0, word_count = 0;

// 	while ((ch = getchar()) != EOF)
// 	{
// 		if (isalpha(ch)) // if ch is a letter
// 		{
// 			letter_count++;
// 			// if not currently in a word, then switch state to in word
// 			// and increment the word count
// 			if (!in_word) 
// 			{
// 				in_word = true;
// 				word_count++;
// 			}
// 		}
// 		// if ch is not a letter, set program state to out of word
// 		else 
// 			in_word = false;
// 	}
// 	// divide letter count by word count to get average letters/word
// 	printf("Average letters per word: %.2f\n", (float) letter_count / word_count);

// 	return 0;
// }
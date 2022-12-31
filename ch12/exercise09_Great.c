// C Primer Plus
// Chapter 12 

// Write a program with the following behavior. First, it asks you how many
// words you wish to enter. Then it has you enter the words, and then it
// displays the words. Use malloc() and the answer to the first question (the
// number of words) to create a dynamic array of the corresponding number of
// pointers-to-char. (Note that because each element in the array is a pointer-
// to-char, the pointer used to store the return value of malloc() should be a
// pointer-to-a-pointer-to-char.) When reading the string, the program should
// read the word into a temporary array of char, use malloc() to allocate
// enough storage to hold the word, and store the address in the array of char
// pointers. Then it should copy the word from the temporary array into the
// allocated storage. Thus, you wind up with an array of character pointers,
// each pointing to an object of the precise size needed to store the
// particular word. A sample run could look like this:
// 	> How many words do you wish to enter? 
//    5
//  > Enter 5 words now:
// 	  I enjoyed doing this exerise
// 	> Here are your words:
// 	  I 
//    enjoyed 
//    doing
//    this
//    exercise

#include <stdio.h>
#include <stdlib.h>	// malloc
#include <string.h>	// strncpy
#define MAX_CHAR 20	// max number of characters for each word (truncate otherwise)

int main()
{
	printf("How many words do you wish to enter?\n");
	int words;
	char temp[MAX_CHAR];	// temporary array of char to hold a word
	char ch;
	scanf("%d", &words);
	while (getchar() != '\n')
		continue;	// clear buffer
	printf("Enter %d words now:\n", words);
	char ** pwords = (char **)malloc(words * sizeof(char *));	// pointer to pointer to char
	int i = 0;
	int wordCount = 0;
	while ((ch = getchar()) != '\n'){
		if (ch != 32){	// 32 is equivalent to Space
			temp[i++] = ch;
		} else if (ch == 32){
			// allocate the proper dynamic memory for the new word
			pwords[wordCount] = (char *)malloc((i+1) * sizeof(char));
			// store the word to the pointer array, update wordCount
			strncpy(pwords[wordCount], temp, i);
			pwords[wordCount][i] = '\0';
			printf("Captured word \"%s\" and stored in pwords[%d],\n", pwords[wordCount], wordCount);
			i = 0;	// reset i
			wordCount++;
		}
	}
	pwords[wordCount] = (char *)malloc((i+1) * sizeof(char));
	strncpy(pwords[wordCount], temp, i);
	pwords[wordCount][i+1] = '\0';
	printf("Captured word: ""%s"" and stored in pwords[%d],\n", pwords[wordCount], wordCount);
	wordCount++;
	printf("The words stored are:\n");
	for (int i  = 0; i < words; i++){
		printf("%s\n", *(pwords + i));
	}
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define LIMIT 400

// char ** get_words(int n);
// static void find_word(char **start, char **end);

// int main(void)
// {
// 	int n;
// 	char ** words;

// 	printf("How many words do you wish to enter?\n");
// 	if (scanf("%d", &n) == 1 && n > 0)
// 	{
// 		while (getchar() != '\n')
// 			continue;
// 		words = get_words(n);

// 		printf("Here are your words:\n");
// 		for (int i = 0; i < n; i++)
// 			printf("%s\n", words[i]);
// 	}

// 	return 0;
// }

// char ** get_words(int n)
// {
// 	char tmp[LIMIT];
// 	int i;
// 	char * word_start;
// 	char * word_end;
// 	int word_length;

// 	char ** word_array = (char **) malloc(n * sizeof(char *));

// 	printf("Enter %d words now:\n", n);
// 	word_start = fgets(tmp, LIMIT, stdin);

// 	for (i = 0; i < n; i++)
// 	{
// 		// find the start and end of next word
// 		find_word(&word_start, &word_end);
		
// 		// if word_start points to null char, there are no more
// 		// words to find; exit loop
// 		if (*word_start == '\0')
// 			break;

// 		// allocate memory for new word and copy from tmp
// 		word_length = word_end - word_start;
// 		word_array[i] = (char *) malloc((word_length + 1) * sizeof(char));
// 		if (word_array[i] != NULL)
// 		{
// 			strncpy(word_array[i], word_start, word_length);
// 			word_array[i][word_length] = '\0';
// 		}
		
// 		word_start = word_end;
// 	}

// 	// if less than n words found, set remaining elements of
// 	// word_array to null string
// 	if (i < n)
// 		for (; i < n; i++)
// 		{	
// 			word_array[i] = (char *) malloc(sizeof(char));
// 			*word_array[i] = '\0';
// 		}

// 	return word_array;
// }

// static void find_word(char **start, char **end)
// {
// 	// takes two pointers to pointers to char
// 	// sets *start to point to first character of first
// 	// word occuring after **start and sets *end to point
// 	// to the character immediately after the word

// 	while (isspace(**start))
// 		(*start)++;

// 	*end = *start;

// 	while (!isspace(**end) && **end != '\0')
// 		(*end)++;
// }



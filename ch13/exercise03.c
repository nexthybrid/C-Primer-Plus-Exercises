// C Primer Plus
// Chapter 13 Exercise 3:

// Write a file copy program that prompts the user to enter the name of a text
// file to act as the source file and the name of an output file. The program
// should use the toupper() function from ctype.h to convert all text to
// uppercase as it’s written to the output file. Use standard I/O and the text
// mode.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME_LEN_MAX 20
#define BUFF_SIZE 1024

void char_arr_to_upper(char * arr, int n);

int main()
{
	printf("Enter the source file name:\n");
	char srcFile[NAME_LEN_MAX];
	scanf("%s", srcFile);
	printf("Enter the output file name:\n");
	char tgtFile[NAME_LEN_MAX];
	scanf("%s", tgtFile);
	FILE *fpSrc, *fpTgt;
	if ((fpSrc = fopen(srcFile, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", srcFile);
		exit(1);
	}
	if ((fpTgt = fopen(tgtFile, "w")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", tgtFile);
		exit(2);
	}
	char buffer[BUFF_SIZE];
	int n;
	while ((n = fread(buffer, sizeof(char), BUFF_SIZE, fpSrc)) != 0){
		char_arr_to_upper(buffer, n);	// convert to upper case
		fwrite(buffer, sizeof(char), n, fpTgt);
	}
	return 0;
}

// turn lower case chars to upper case chars in arr, with length n
void char_arr_to_upper(char * arr, int n)
{
	for (int i = 0; i < n; i++){
		arr[i] = toupper(arr[i]);
	}
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define SLEN 81

// void get(char * string, int n);

// int main(void)
// {
// 	int ch;
// 	FILE * fsource;
// 	FILE * fdest;
// 	char source[SLEN];
// 	char dest[SLEN];

// 	printf("Enter a source file: ");
// 	get(source, SLEN);
// 	printf("Enter a destination file: ");
// 	get(dest, SLEN);

// 	if ((fsource = fopen(source, "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s for read.\n", source);
// 		exit(EXIT_FAILURE);
// 	}
// 	if ((fdest = fopen(dest, "w")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s for write.\n", dest);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((ch = getc(fsource)) != EOF)
// 	{
// 		if (islower(ch))
// 			ch = toupper(ch);
// 		putc(ch, fdest);
// 	}

// 	fclose(fsource);
// 	fclose(fdest);

// 	return 0;
// }

// void get(char * string, int n)
// {
// 	// wrapper for fgets - read from stdin and replace
// 	// first newline with null character

// 	fgets(string, n, stdin);

// 	while (*string != '\0')
// 	{
// 		if (*string == '\n')
// 		{
// 			*string = '\0';
// 			break;
// 		}
// 		string++;
// 	}
// }
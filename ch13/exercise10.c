// C Primer Plus
// Chapter 13 Exercise 10:

// Write a program that opens a text file whose name is obtained interactively.
// Set up a loop that asks the user to enter a file position. The program then
// should print the part of the file starting at that position and proceed to
// the next newline character. Let negative or nonnumeric input terminate the
// user-input loop.

#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 20
#define LINE_BUFF_SIZE 256

int main()
{
	printf("Enter a filename:\n");
	char filename[MAX_CHAR];
	scanf("%s", filename);
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.", filename);
		exit(1);
	}
	int usrPos;
	char buffer[LINE_BUFF_SIZE];
	printf("Enter a position (non-negative integer), or exit using a negative integer:\n");
	while (scanf("%d", &usrPos) == 1 && usrPos >= 0){
		fpos_t filePos = usrPos;
		fsetpos(fp, &filePos);
		fgets(buffer, LINE_BUFF_SIZE, fp);
		fputs(buffer,stdout);
		printf("Enter a position (non-negative integer), or exit using a negative integer:\n");
	}
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// #define SLEN 81

// void get(char * string, int n);

// int main(void)
// {
// 	FILE *fp;
// 	char filename[SLEN];
// 	long pos;
// 	int ch;

// 	printf("Enter a filename: ");
// 	get(filename, SLEN);

// 	if ((fp = fopen(filename, "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", filename);
// 		exit(EXIT_FAILURE);
// 	}

// 	printf("Enter a position: ");
// 	while (scanf("%ld", &pos) == 1)
// 	{
// 		if (pos < 0)
// 			break;

// 		fseek(fp, pos, SEEK_SET);
// 		while ((ch = getc(fp)) != EOF && ch != '\n')
// 			putchar(ch);
// 		putchar('\n');

// 		printf("Enter a positition: ");
// 	}

// 	fclose(fp);
// 	puts("Done.");
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

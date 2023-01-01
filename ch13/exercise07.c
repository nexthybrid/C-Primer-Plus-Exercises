// C Primer Plus
// Chapter 13 Exercise 7:

// Write a program that opens two files. You can obtain the filenames either by
// using command-line arguments or by soliciting the user to enter them.
//   a. Have the program print line 1 of the first file, line 1 of the second
// 		file, line 2 of the first file, line 2 of the second file, and so on,
// 		until the last line of the longer file (in terms of lines) is printed.
//   b. Modify the program so that lines with the same line number are printed
// 		on the same line.

#include <stdio.h>
#include <stdlib.h>
#define LINE_BUFF_SIZE 256

void print_same_lines(char * file1, char * file2);
void print_same_lines_mod(char * file1, char * file2);

int main(int argc, char * argv[])
{
	if (argc != 3){
		fprintf(stderr, "Usage: ./a.exe <filename1> <filename2>\n");
		exit(1);
	}
	print_same_lines(argv[1], argv[2]);
	printf("\n\n\nModified version:\n\n");
	print_same_lines_mod(argv[1], argv[2]);
	return 0;
}

// print file1 line1, file2 line1, file1 line2, file2 line 2, ... on different lines
void print_same_lines(char * file1, char * file2)
{
	FILE *fp1, *fp2;
	if ( (fp1 = fopen(file1, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", file1);
		exit(2);
	}
	if ( (fp2 = fopen(file2, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", file2);
		exit(3);
	}
	setvbuf(fp1, NULL, _IOLBF, LINE_BUFF_SIZE);
	setvbuf(fp2, NULL, _IOLBF, LINE_BUFF_SIZE);
	// use fgets() to read lines up to the next newline character
	// and print to stdout
	char lineFile1[LINE_BUFF_SIZE];
	char lineFile2[LINE_BUFF_SIZE];
	char *str1 = fgets(lineFile1, LINE_BUFF_SIZE, fp1);
	char *str2 = fgets(lineFile2, LINE_BUFF_SIZE, fp2);
	while ( str1 != NULL || str2 != NULL){
		fputs(lineFile1, stdout);
		fputs(lineFile2, stdout);
		str1 = fgets(lineFile1, LINE_BUFF_SIZE, fp1);
		str2 = fgets(lineFile2, LINE_BUFF_SIZE, fp2);
	}
}

// print file1 line1 and file2 line1 on the same line
// print file1 line2 and file2 line2 on the same line, ...
void print_same_lines_mod(char * file1, char * file2)
{
	FILE *fp1, *fp2;
	if ( (fp1 = fopen(file1, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", file1);
		exit(2);
	}
	if ( (fp2 = fopen(file2, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", file2);
		exit(3);
	}
	setvbuf(fp1, NULL, _IOLBF, LINE_BUFF_SIZE);
	setvbuf(fp2, NULL, _IOLBF, LINE_BUFF_SIZE);
	// use fgets() to read lines up to the next newline character
	// and print to stdout
	char lineFile1[LINE_BUFF_SIZE];
	char lineFile2[LINE_BUFF_SIZE];
	char *str1 = fgets(lineFile1, LINE_BUFF_SIZE, fp1);
	// need to remove the newline '\n' from lineFile1.
	for (int i = 0; lineFile1[i] != '\0'; i++){
		if (lineFile1[i] == '\n')
			lineFile1[i] = '\0';	// replace '\n' with '\0'
	}
	char *str2 = fgets(lineFile2, LINE_BUFF_SIZE, fp2);
	while ( str1 != NULL || str2 != NULL){
		fputs(lineFile1, stdout);
		fputs(lineFile2, stdout);
		str1 = fgets(lineFile1, LINE_BUFF_SIZE, fp1);
		for (int i = 0; lineFile1[i] != '\0'; i++){
			if (lineFile1[i] == '\n')
				lineFile1[i] = '\0';	// replace '\n' with '\0'
		}
		str2 = fgets(lineFile2, LINE_BUFF_SIZE, fp2);
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// #define LLEN 70 

// void fget(char * string, int n, FILE *file);

// int main(int argc, char *argv[])
// {
// 	FILE *file1, *file2;
// 	char tmp[LLEN];
// 	int ch;

// 	if (argc < 3)
// 	{
// 		printf("Usage: %s file1 file2\n", argv[0]);
// 		exit(EXIT_FAILURE);
// 	}

// 	if ((file1 = fopen(argv[1], "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", argv[1]);
// 		exit(EXIT_FAILURE);
// 	}
// 	if ((file2 = fopen(argv[2], "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", argv[2]);
// 		exit(EXIT_FAILURE);
// 	}

// 	while (1)
// 	{
// 		fget(tmp, LLEN, file1);
// 		printf("%-*s\n", LLEN, tmp);
// 		fget(tmp, LLEN, file2);
// 		if (feof(file1) && feof(file2))
// 			break;
// 	}

// 	return 0;
// }

// void fget(char * string, int n, FILE *file)
// {
// 	// wrapper for fgets - replaces
// 	// first newline with null character

// 	fgets(string, n, file);

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
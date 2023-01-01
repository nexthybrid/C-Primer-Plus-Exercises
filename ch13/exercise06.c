// C Primer Plus
// Chapter 13 Exercise 6:

// Programs using command-line arguments rely on the user’s memory of how to
// use them correctly. Rewrite the program in Listing 13.2 so that, instead of
// using command-line arguments, it prompts the user for the required
// information.

// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h> // for strcpy(), strcat()
#define LEN 40
int main()
{
	FILE *in, *out; // declare two FILE pointers
	int ch;
	char name[LEN]; // storage for output filename
	char sourceName[LEN];	// source file name
	int count = 0;
	printf("Enter the source filename:\n");
	scanf("%s", sourceName);
	// set up input
	if ((in = fopen(sourceName, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", sourceName);
		exit(2);
	}
	// set up output
	strncpy(name,sourceName, LEN - 5); // copy filename
	name[LEN - 5] = '\0';
	strcat(name,".red"); // append .red
	if ((out = fopen(name, "w")) == NULL)
	{ // open file for writing
		fprintf(stderr,"Can't create output file.\n");
		exit(3);
	}
	// copy data
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out); // print every 3rd char
	// clean up
	if (fclose(in) != 0 || fclose(out) != 0)
	fprintf(stderr,"Error in closing files\n");
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define SLEN 81

// void get(char * string, int n);

// int main(void)
// {
// 	FILE *in;
// 	FILE *out;
// 	char source[SLEN];
// 	char dest[SLEN];
// 	int ch;
// 	unsigned int count = 0;

// 	printf("Enter a file to reduce: ");
// 	get(source, SLEN - 5);

// 	if ((in = fopen(source, "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", source);
// 		exit(EXIT_FAILURE);
// 	}

// 	strcpy(dest, source);
// 	strcat(dest, ".red");
// 	if ((out = fopen(dest, "w")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", dest);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((ch = getc(in)) != EOF)
// 		if (count++ % 3 == 0)
// 			putc(ch, out);

// 	if (fclose(in) != 0)
// 		printf("Error in closing file %s.\n", source);
// 	if (fclose(out) != 0)
// 		printf("Error in closing file %s.\n", dest);

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
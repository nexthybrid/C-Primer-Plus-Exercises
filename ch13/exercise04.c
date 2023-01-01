// C Primer Plus
// Chapter 13 Exercise 4:

// Write a program that sequentially displays onscreen all the files listed in
// the command line. Use argc to control a loop.

#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

void printFile(char *filename);

int main(int argc, char * argv[])
{
	if (argc < 2){
		fprintf(stderr, "Usage: ./a.exe <filename1> (optional)<filename2>\n");
		exit(1);
	}
	for (int i = 1; i < argc; i++){
		printFile(argv[i]);
	}
	return 0;
}

void printFile(char * filename)
{
	FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s, skipping to the next file.\n", filename);
		fclose(fp);
		return;
	}
	char buffer[BUFF_SIZE];
	int n;
	while ( (n = fread(buffer, sizeof(char), BUFF_SIZE, fp)) != 0)
		fwrite(buffer, sizeof(char), n, stdout);
	return;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {
// 	FILE * fp;
// 	int ch;

// 	if (argc == 1)
// 	{
// 		printf("Usage: %s file1 file2 ...\n", argv[0]);
// 		exit(EXIT_FAILURE);
// 	}
// 	for (int i = 1; i < argc; i++)
// 	{
// 		if ((fp = fopen(argv[i], "r")) == NULL)
// 		{
// 			fprintf(stderr, "Could not open file %s.\n", argv[i]);
// 			exit(EXIT_FAILURE);
// 		}

// 		while ((ch = getc(fp)) != EOF)
// 			putc(ch, stdout);

// 		fclose(fp);
// 	}

// 	return 0;
// }
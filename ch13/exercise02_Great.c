// C Primer Plus
// Chapter 13 Exercise 2:

// Write a file-copy program that takes the original filename and the copy file
// from the command line. Use standard I/O and the binary mode, if possible.

/* KNOWLEDGE LEARNED:
	If not careful, garbage can be sent to the target file because of non-initialized
	buffer. The garbage apprears at the end of the file.

	To avoid generating and writing garbage, always use fwrite with a meaningful 
	parameter of _elementCount.
*/

#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1024


int main(int argc, char * argv[])
{
	if (argc < 3 || argc > 3){
		fprintf(stderr, "Usage: ./a.exe <source> <target>\n");
		exit(1);
	}
	FILE * fsrc, * ftgt;
	if ((fsrc = fopen(argv[1], "rb")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", argv[1]);
		exit(2);
	}
	if ((ftgt = fopen(argv[2], "wb")) == NULL){
		fprintf(stderr, "Cannot open file %s.\n", argv[2]);
		exit(3);
	}
	char buffer[BUFF_SIZE];	// assume the file is of characters
	int n;
	while ((n = fread(buffer, sizeof(char), BUFF_SIZE, fsrc)) != 0){
		printf("n = %d.\n", n);
		if (n == BUFF_SIZE)
			fwrite(buffer, sizeof(char), BUFF_SIZE, ftgt);
		else if (n < BUFF_SIZE){
			// EOF reached during this fread, we use n to fwrite instead.
			fwrite(buffer, sizeof(char), n, ftgt);
		}
	}
	fclose(fsrc);
	fclose(ftgt);
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {
// 	int ch;
// 	FILE * fsource;
// 	FILE * fdest;

// 	if (argc != 3)
// 	{
// 		printf("Usage: %s source_file destination_file\n", argv[0]);
// 		exit(EXIT_FAILURE);
// 	}

// 	if ((fsource = fopen(argv[1], "rb")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s for read\n", argv[1]);
// 		exit(EXIT_FAILURE);
// 	}
// 	if ((fdest = fopen(argv[2], "wb")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s for write\n", argv[2]);
// 		exit(EXIT_FAILURE);
// 	}

// 	while ((ch = getc(fsource)) != EOF)
// 		putc(ch, fdest);

// 	fclose(fsource);
// 	fclose(fdest);

// 	return 0;
// }
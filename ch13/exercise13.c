// C Primer Plus
// Chapter 13 Exercise 13:

// Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of
// standard arrays.

// Note: use data.txt as input file to test this program.

#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX 20
#define DIM1 20
#define DIM2 30

void read_into_int_array_VLA(int dim1, int dim2, int array[dim1][dim2], char *filename);
void int_to_char_array_VLA(int dim1, int dim2, char charArr[dim1][dim2+1], int array[dim1][dim2]);
void display_char_array_VLA(int dim1, int dim2, char charArr[dim1][dim2+1]);
void save_to_file_VLA(int dim1, int dim2, char charArr[dim1][dim2+1]);


int main()
{
	printf("Enter the data filename:\n");
	char filename[NAME_MAX];
	scanf("%s", filename);
	int intArr[DIM1][DIM2];
	char charArr[DIM1][DIM2+1];
	read_into_int_array_VLA(DIM1, DIM2, intArr, filename);
	int_to_char_array_VLA(DIM1, DIM2, charArr, intArr);
	display_char_array_VLA(DIM1, DIM2, charArr);
	save_to_file_VLA(DIM1, DIM2, charArr);
	return 0;
}

void read_into_int_array_VLA(int dim1, int dim2, int array[dim1][dim2], char *filename)
{
	FILE * fp;
	if ( (fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open %s.\n", filename);
		exit(1);
	}
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2; j++)
			if (fscanf(fp, "%d", &array[i][j]) == 0){
				fprintf(stderr, "fscanf cannot find a value.\n");
				exit(2);
			}
}

void save_to_file_VLA(int dim1, int dim2, char charArr[dim1][dim2+1])
{
	char *filename = "file_ex12.txt";
	FILE * fp;
	if ((fp = fopen(filename, "w+")) == NULL){
		fprintf(stderr, "Cannot open %s", filename);
		exit(3);
	}
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2 + 1; j++)
			fprintf(fp, "%c", charArr[i][j]);
}

void display_char_array_VLA(int dim1, int dim2, char charArr[dim1][dim2+1])
{
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2 + 1; j++)
			printf("%c", charArr[i][j]);
}

void int_to_char_array_VLA(int dim1, int dim2, char charArr[dim1][dim2+1], int array[dim1][dim2])
{
	// conversion rules:
	//0 (space) 1 . 2 , 3 : 4 ; 5 * 6 + 7 % 8 & 9 #
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim2 + 1; j++){
			if (j == DIM2)
				charArr[i][j] = '\n';
			else
				switch(array[i][j]){
					case 0:
						charArr[i][j] = ' ';
						break;
					case 1:
						charArr[i][j] = '.';
						break;
					case 2:
						charArr[i][j] = ',';
						break;
					case 3:
						charArr[i][j] = ':';
						break;
					case 4:
						charArr[i][j] = ';';
						break;
					case 5:
						charArr[i][j] = '*';
						break;
					case 6:
						charArr[i][j] = '+';
						break;
					case 7:
						charArr[i][j] = '%';
						break;
					case 8:
						charArr[i][j] = '&';
						break;
					case 9:
						charArr[i][j] = '#';
						break;
					default:
						charArr[i][j] = ' ';
				}
		}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <stdbool.h>

// int main(int argc, char *argv[])
// {
// 	FILE *fp;
// 	int ch;
// 	int rows = 0, cols = 0, lastrow_cols;
// 	bool first_line;

// 	if (argc != 3)
// 	{
// 		printf("Usage: %s <data file> <image file>\n", argv[0]);
// 		exit(EXIT_FAILURE);
// 	}

// 	// open data file
// 	if ((fp = fopen(argv[1], "r")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", argv[1]);
// 		exit(EXIT_FAILURE);
// 	}

// 	// this passage of code counts the number of columns in each row
// 	// and compares them for consistency, exiting with an error if they're
// 	// not all equal
// 	first_line = true;
// 	while ((ch = getc(fp)) != EOF && isdigit(ch))
// 	{	

// 		cols = 1;
// 		while ((ch = getc(fp)) != EOF && ch != '\n')
// 			if (isdigit(ch))
// 				cols++;
// 		if (first_line)
// 		{
// 			first_line = false;
// 		}
// 		else
// 		{
// 			if (cols != lastrow_cols)
// 			{
// 				fprintf(stderr, "Invalid data file: unequal number of columns in rows.\n");
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		lastrow_cols = cols;
// 	}
// 	if (cols == 0)
// 	{
// 		fprintf(stderr, "Invalid data file.\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	// this passage counts the number of rows
// 	rewind(fp);
// 	while ((ch = getc(fp)) != EOF)
// 		if (ch == '\n')
// 			rows++;

// 	// with the number of rows and columns counted, the data and img arrays
// 	// can be allocated dynamically
// 	int data[rows][cols];
// 	char img[rows][cols + 1];

// 	// read ints from file
// 	rewind(fp);
// 	for (int i = 0; i < rows; i++)
// 		for (int j = 0; j < cols; j++)
// 			if (fscanf(fp, "%d", *(data + i) + j) != 1)
// 			{
// 				fprintf(stderr, "Invalid data file.\n");
// 				exit(EXIT_FAILURE);
// 			}
// 	fclose(fp); // done with data file

// 	// convert ints to characters
// 	for (int i = 0; i < rows; i++)
// 	{	
// 		int j;
// 		for (j = 0; j < cols; j++)
// 		{
// 			switch (data[i][j])
// 			{
// 				case(0):
// 					ch = ' ';
// 					break;
// 				case(1):
// 					ch = '.';
// 					break;
// 				case(2):
// 					ch = '\'';
// 					break;
// 				case(3):
// 					ch = ':';
// 					break;
// 				case(4):
// 					ch = '~';
// 					break;
// 				case(5):
// 					ch = '*';
// 					break;
// 				case(6):
// 					ch = '=';
// 					break;
// 				case(7):
// 					ch = '}';
// 					break;
// 				case(8):
// 					ch = '&';
// 					break;
// 				case(9):
// 					ch = '#';
// 					break;
// 				default:
// 					fprintf(stderr, "Error: int out of bounds.\n");
// 					exit(EXIT_FAILURE);
// 			}
// 			img[i][j] = ch;
// 		}
// 		img[i][j] = '\0'; // j = cols here
// 	}

// 	// open image file
// 	if ((fp = fopen(argv[2], "w")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", argv[2]);
// 		exit(EXIT_FAILURE);
// 	}

// 	for (int i = 0; i < rows; i++)
// 	{
// 		// print to console and file
// 		puts(img[i]);
// 		fprintf(fp, "%s\n", img[i]);
// 	}
// 	fclose(fp);

// 	return 0;
// }
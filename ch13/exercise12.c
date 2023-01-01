// C Primer Plus
// Chapter 13 Exercise 12:

// Create a text file consisting of 20 rows of 30 integers. The integers should
// be in the range 0–9 and be separated by spaces. The file is a digital
// representation of a picture, with the values 0 through 9 representing
// increasing levels of darkness. Write a program that reads the contents of
// the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use
// the values in this array to initialize a 20-by-31 array of chars, with a 0
// value corresponding to a space character, a 1 value to the period character,
// and so on, with each larger number represented by a character that occupies
// more space. For example, you might use # to represent 9. The last character
// (the 31st) in each row should be a null character, making it an array of 20
// strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file.

// Note: use data.txt as input file to test this program.

#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX 20
#define DIM1 20
#define DIM2 30

void read_into_int_array(int array[DIM1][DIM2], char *filename);
void int_to_char_array(char charArr[DIM1][DIM2+1], int array[DIM1][DIM2]);
void display_char_array(char charArr[DIM1][DIM2+1]);
void save_to_file(char charArr[DIM1][DIM2+1]);


int main()
{
	printf("Enter the data filename:\n");
	char filename[NAME_MAX];
	scanf("%s", filename);
	int intArr[DIM1][DIM2];
	char charArr[DIM1][DIM2+1];
	read_into_int_array(intArr, filename);
	int_to_char_array(charArr, intArr);
	display_char_array(charArr);
	save_to_file(charArr);
	return 0;
}

void read_into_int_array(int array[DIM1][DIM2], char *filename)
{
	FILE * fp;
	if ( (fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open %s.\n", filename);
		exit(1);
	}
	for (int i = 0; i < DIM1; i++)
		for (int j = 0; j < DIM2; j++)
			if (fscanf(fp, "%d", &array[i][j]) == 0){
				fprintf(stderr, "fscanf cannot find a value.\n");
				exit(2);
			}
}

void save_to_file(char charArr[DIM1][DIM2+1])
{
	char *filename = "file_ex12.txt";
	FILE * fp;
	if ((fp = fopen(filename, "w+")) == NULL){
		fprintf(stderr, "Cannot open %s", filename);
		exit(3);
	}
	for (int i = 0; i < DIM1; i++)
		for (int j = 0; j < DIM2 + 1; j++)
			fprintf(fp, "%c", charArr[i][j]);
}

void display_char_array(char charArr[DIM1][DIM2+1])
{
	for (int i = 0; i < DIM1; i++)
		for (int j = 0; j < DIM2 + 1; j++)
			printf("%c", charArr[i][j]);
}

void int_to_char_array(char charArr[DIM1][DIM2+1], int array[DIM1][DIM2])
{
	// conversion rules:
	//0 (space) 1 . 2 , 3 : 4 ; 5 * 6 + 7 % 8 & 9 #
	for (int i = 0; i < DIM1; i++)
		for (int j = 0; j < DIM2 + 1; j++){
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

// #define ROWS 20
// #define COLS 30

// int main(int argc, char *argv[])
// {
// 	FILE *fp;
// 	int data[ROWS][COLS];
// 	char img[ROWS][COLS + 1];
// 	char ch;

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

// 	// read ints from file
// 	for (int i = 0; i < ROWS; i++)
// 		for (int j = 0; j < COLS; j++)
// 			if (fscanf(fp, "%d", *(data + i) + j) != 1)
// 			{
// 				fprintf(stderr, "Invalid or corrupted data file.\n");
// 				exit(EXIT_FAILURE);
// 			}
// 	fclose(fp); // done with fp for now

// 	// convert ints to characters
// 	for (int i = 0; i < ROWS; i++)
// 	{	
// 		int j;
// 		for (j = 0; j < COLS; j++)
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
// 		img[i][j] = '\0'; // j = COLS here
// 	}

// 	// open image file
// 	if ((fp = fopen(argv[2], "w")) == NULL)
// 	{
// 		fprintf(stderr, "Could not open file %s.\n", argv[2]);
// 		exit(EXIT_FAILURE);
// 	}

// 	for (int i = 0; i < ROWS; i++)
// 	{
// 		// print to console and file
// 		puts(img[i]);
// 		fprintf(fp, "%s\n", img[i]);
// 	}
// 	fclose(fp);

// 	return 0;
// }
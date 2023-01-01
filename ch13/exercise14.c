// C Primer Plus
// Chapter 13 Exercise 14:

// Digital images, particularly those radioed back from spacecraft, may have
// glitches. Add a de-glitching function to programming exercise 12. It should
// compare each value to its immediate neighbors to the left and right, above
// and below. If the value differs by more than 1 from each of its neighbors,
// replace the value with the average of the neighboring values. You should
// round the average to the nearest integer value. Note that the points along
// the boundaries have fewer than four neighbors, so they require special
// handling.

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
void de_glitch(int array[DIM1][DIM2]);


int main()
{
	printf("Enter the data filename:\n");
	char filename[NAME_MAX];
	scanf("%s", filename);
	int intArr[DIM1][DIM2];
	char charArr[DIM1][DIM2+1];
	read_into_int_array(intArr, filename);
	de_glitch(intArr);
	int_to_char_array(charArr, intArr);
	display_char_array(charArr);
	save_to_file(charArr);
	return 0;
}

void de_glitch(int a[DIM1][DIM2])
{
	int nw, n, ne, e, se, s, sw, w, nNeighbours;
	for (int i = 0; i < DIM1; i++)
		for (int j = 0; j < DIM2; j++){
			nw = a[i][j] - a[i-1][j-1];
			n  = a[i][j] - a[i-1][j  ];
			ne = a[i][j] - a[i-1][j+1];
			e  = a[i][j] - a[i  ][j+1];
			se = a[i][j] - a[i+1][j+1];
			s  = a[i][j] - a[i+1][j  ];
			sw = a[i][j] - a[i+1][j-1];
			nNeighbours = 8;
			// special cases: edges but not corners
			if (i == 0){
				nw = n = ne = 0;
				nNeighbours = 5;
			}
			if (i == DIM1-1){
				sw = s = se = 0;
				nNeighbours = 5;
			}
			if (j == 0){
				nw = w = sw = 0;
				nNeighbours = 5;
			}
			if (j == DIM2-1){
				ne = e = se = 0;
				nNeighbours = 5;
			}
			// special cases: four corners
			if (i == 0 && j == 0){
				nw = n = ne = w = sw = 0;
				nNeighbours = 3;
			}
			if (i == 0 && j == DIM2-1){
				nw = n = ne = e = se = 0;
				nNeighbours = 3;
			}
			if (i == DIM1-1 && j == 0){
				nw = w = sw = s = se = 0;
				nNeighbours = 3;
			}
			if (i == DIM1-1 && j == DIM2-1){
				ne = e = sw = s = se = 0;
				nNeighbours = 3;
			}
			// check if there is any violation
			if (nw > 1 || nw < -1 || n > 1 || n < -1 || ne > 1 || ne < -1 ||
				 w > 1 ||  w < -1 || 					 e > 1 ||  e < -1 || 
				sw > 1 || sw < -1 || s > 1 || s < -1 || se > 1 || se < -1){
				a[i][j] = (nw + n + ne + e + se + s + sw + w) / nNeighbours;
			}
		}
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
// #include <math.h>

// #define ROWS 20
// #define COLS 30

// void deglitch(int data[ROWS][COLS]);

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

// 	// de-glitch the data
// 	deglitch(data);

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

// void deglitch(int data[ROWS][COLS])
// {
// 	float total;
// 	int count;

// 	for (int i = 0; i < ROWS; i++)
// 		for (int j = 0; j < COLS; j++)
// 		{
// 			total = 0;
// 			count = 0;
// 			if (i + 1 < ROWS)
// 			{
// 				if (abs(data[i][j] - data[i + 1][j]) < 2)
// 					continue;

// 				total += data[i + 1][j];
// 				count++;
// 			}
// 			if (j + 1 < COLS)
// 			{
// 				if (abs(data[i][j] - data[i][j + 1]) < 2)
// 					continue;
				
// 				total += data[i][j + 1];
// 				count++;
// 			}
// 			if (i > 0)
// 			{
// 				if (abs(data[i][j] - data[i - 1][j]) < 2)
// 					continue;
				
// 				total += data[i - 1][j];
// 				count++;
// 			}
// 			if (j > 0)
// 			{
// 				if (abs(data[i][j] - data[i][j - 1]) < 2)
// 					continue;
				
// 				total += data[i][j - 1];
// 				count++;
// 			}
			
// 			// if none of the continue statements have been triggered,
// 			// replace data[i][j] with the rounded average of its neighbors
// 			data[i][j] = (int) rintf(total / count);
// 		}
// }
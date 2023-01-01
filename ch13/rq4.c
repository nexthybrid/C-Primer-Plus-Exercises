/* Either directly run ./a.exe or 
    ./a.exe data_rq4.txt
*/

#include <stdio.h>
#include <ctype.h>  // isspace
#include <stdlib.h> // atof
#define MAX_ARR_SIZE 10
#define BUFF_SIZE 20

float calculate_average(float buffer[BUFF_SIZE], int N)
{
    float average = 0;
    for (int i = 0; i < N; i++){
        average += buffer[i];
    }
    average /= (float)N;
    return average;
}

int main(int argc, char * argv[])
{
    FILE * inStream;
    if (argc == 1){
        inStream = stdin;
        printf("Using stdin as input stream.\n");
    }
    else if (argc == 2){
        inStream = fopen(argv[1], "r");
        printf("Using the specified file '%s' as input stream.\n", argv[1]);
    }
    // read floats from input stream
    float array[MAX_ARR_SIZE];
    char buffer[BUFF_SIZE];
    int i = 0;
    int numOfFloats = 0;
    char ch;
    while ((ch = fgetc(inStream)) != EOF){
        if (ch == ' ' || ch == '\n'){
            array[numOfFloats++] = atof(buffer);
            i = 0;
            if (ch == '\n'){
                break;
            }

        } else {
            buffer[i++] = ch;
        }
    }
    float average = calculate_average(array, numOfFloats);
    printf("The average of values: %.3f.\n", average);
    return 0;
}
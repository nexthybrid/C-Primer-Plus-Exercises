/* running syntax: ./a.exe <char> <filename>
    e.g.,   ./a.exe r Frost.txt
    Behavior: only prints the lines containing the specified character in the file.
*/

/* OBSERVATIONS:
    Whether using _IOLBF or _IOFBF does not change the output behavior of the code.
*/

#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 256

void printMatched(char ch, FILE * fp);

int main(int argc, char * argv[])
{
    if (argc < 3 || argc > 3)
        printf("Usage: ./a.exe <char> <filename>\n");
    // find and print the lines containing argv[1]
    FILE * fp;
    fp = fopen(argv[2], "r");
    printMatched(*(argv[1]), fp);
    return 0;
}

void printMatched(char ch, FILE * fp)
{
    // use a custom buffer that is line-buffered, meaning a '\n' will trigger flushing
    setvbuf(fp, NULL, _IOLBF, BUFF_SIZE);
    // set the stdout buffer using the same line-buffered setting
    setvbuf(stdout, NULL, _IOLBF, BUFF_SIZE);
    // use fgets, which terminates when a newline is detected
    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, fp) != NULL){
        // check if ch is in line, if true print the line
        for (int i = 0; line[i] != '\0'; i++){
            if (line[i] == ch)
                fputs(line, stdout);
        }
    }
}
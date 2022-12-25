#include <stdio.h>
#include <string.h> // strlen
#define STR_LIM 255
#define STOP '#'


/* this example shows how to redirect words.txt into stdio stream.
redirection command in terminal (Windows 10 OS):
./a.exe < words.txt
*/

/* redirecting output:
    we can also redirect the output of stdout to a file, in terminal type:
    ./a.exe > newfile.txt
*/

/* combined redirection of input and output:
    we can simutaneously use redirect input and redirect output:
    ./a.exe < words.txt > newfile.txt
*/

/* There are other operators than the < and >, e.g., >> (append output),
    | (pipe operator). These are OS-defined operators.
*/

/* PERSONAL KNOWLEDGE:
    getchar() does not work with redirection
    fscanf() works with redirection
*/

int main()
{
    printf("Enter text (terminated by # or EOF):\n");
    // count the total number of characters in the input
    char str[STR_LIM];
    char ch;
    int i = 0;
    // while ((ch = getchar()) != STOP){    // getchar() does not work with redirection
    //     str[i++] = ch;
    // }
    // printf("Total characters: %d\n", i);
    fscanf(stdin, "%[^#]s", str);   // fscanf works with redirection, stdin explicitly called
    printf("Total characters: %zd\n", strlen(str));
    return 0;
}
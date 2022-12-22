#include <stdio.h>
#include <string.h>

/* print a string repeatedly using loops */

void printSmile()
{
    printf("Smile!");
}

void loopPrint(int nTimes)
{
    for (int i = 0; i < nTimes; i++)
        printSmile();
}

int main()
{
    loopPrint(3);
    printf("\n");
    loopPrint(2);
    printf("\n");
    loopPrint(1);
    return 0;
}
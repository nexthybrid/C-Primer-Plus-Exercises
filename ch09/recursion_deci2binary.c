#include <stdio.h>

/* Use recursion to print the binary equivalent of a given integer*/

void printBinary(int);

int main()
{
    printf("Provide a non-negative integer:\n");
    int a;
    scanf("%d", &a);
    printBinary(a);
}

// print the binary equivalent of an integer in decimal form
void printBinary(int a)
{
    // statements before recursion (nothing to print)

    // recursion call
    if (a / 2 != 0) // STOP condition
        printBinary(a / 2);

    // statements after recursion (print the remainder by 2)
    printf("%d", a % 2);
}
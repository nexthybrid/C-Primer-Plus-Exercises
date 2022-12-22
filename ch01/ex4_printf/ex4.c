#include <stdio.h>
#include <string.h>

/* print using dedicated functions */

// print "For he's a jolly good fellow!"
void print1()
{
    printf("For he's a jolly good fellow!\n");
}

// print "Which nobody can deny!"
void print2()
{
    printf("Which nobody can deny!\n");
}

int main()
{
    print1();
    print1();
    print1();
    print2();
    return 0;
}
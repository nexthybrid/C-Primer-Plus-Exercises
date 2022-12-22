#include <stdio.h>
#include <string.h>

/* print with a deciated function */

/* TIP:
    function two() needs to be declared or defined above function one_three()!
*/

void two()
{
    printf("two\n");
}

void one_three()
{
    printf("one\n");
    two();
    printf("three\n");
}

int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");
    return 0;
}
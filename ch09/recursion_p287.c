/* Knowledge and examples of recursion functions*/

/* First point: a recursion function can be divided into two parts:
    (1) statements before the recursion call; (Levels in this example)
    (2) statements after the recursion call. (LEVELs in this example)

    Occurance order:
    1. Ascending order for statements before the recursion call;
    2. Decending order for statements after the recursion call.

    Illustration:

    Level 1
    Level 2
    Level 3
    LEVEL 3
    LEVEL 2
    LEVEL 1
*/

/* Second point: when there are no statements before the recursion call,
    it is called a TAIL RECURSION. The recursion order goes like:
    Level 1
    Level 2
    Level 3
*/

/* Why use recursion instead of for loop?
    Because, according to the C Primer p289, in some cases, there is no
    simple loop alternative.
*/

/* recur.c -- recursion illustration */
#include <stdio.h>

void up_and_down(int);

int main(void)
{
    up_and_down(1);
    return 0;
}

void up_and_down(int n)
{
    printf("Level %d: n location %#p\n", n, &n); /* 1 */
    if (n < 4)
        up_and_down(n+1);   // recursion call
    printf("LEVEL %d: n location %#p\n", n, &n); /* 2 */
}
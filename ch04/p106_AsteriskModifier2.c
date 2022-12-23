/* skip2.c -- skips over first two integers of input */
#include <stdio.h>
int main(void)
{
    int n;
    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &n);    // The '*' modifier makes scanf ignore the first two keyboard inputs
    printf("The last integer was %d\n", n);
    return 0;
}
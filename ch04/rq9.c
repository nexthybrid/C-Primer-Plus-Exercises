#include <stdio.h>

int main()
{
    // d
    char a[10];
    int b;
    scanf("%s %d", a, &b);
    printf("a = %s\nb = %d\n", a, b);

    // e, skipping the string
    scanf("%*s %d", a, &b);
    printf("a = %s\nb = %d\n", a, b);

    return 0;
}
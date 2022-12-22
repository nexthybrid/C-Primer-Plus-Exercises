#include <stdio.h>

/* displaying integer in Octal and Hexadecimal units
*/

int main()
{
    int intVal = 999;
    printf("The integer 999 in different display modes:\n");
    printf("Decimal: %i\nOctal: %o\nHexademical: %x\n", intVal, intVal, intVal);
    printf("Octal with C prefix: %#o\nHexademial with C prefix: %#x\n", intVal, intVal);

    return 0;
}
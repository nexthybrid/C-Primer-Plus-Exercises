#include <stdio.h>
#include <inttypes.h>

/* inttypes.h include more specific integer data types */

int main()
{
    int a = -32767;
    unsigned int b = 65535;
    int16_t c = -32767;
    int32_t d = -2147483647;
    uint32_t e = 4294967295;
    printf("int a = %i\n", a);
    printf("unsigned int b = %i\n", b);
    printf("int16_t c = %i\n", c);
    printf("int32_t d = %ld\n", d);
    printf("uint32_t e = %lu\n", e);

    return 0;
}
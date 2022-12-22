#include <stdio.h>
#include <string.h> // %s

/* print first and last name on one line;
    print first and last name on two lines;
    use two printf to print first and last name on one line.
*/

/* TIP:
    use <string.h> and format identifier %s for printing strings.
*/

int main()
{
    // first and last name variables
    char first[] = "Anton";
    char last[] = "Bruckner";
    // this below does not work because 'first' is treated as a pointer, not char
    // use string with <string.h> instead!
    // printf("%c %c\n", first, last); 
    printf("%s %s\n", first, last); 
    printf("%s\n%s\n", first, last);
    printf("%s", first);
    printf(" %s\n", last);
    return 0;
}
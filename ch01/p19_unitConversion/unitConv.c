#include <stdio.h>

/* prompt user for a inch value, convert it to centimeters
    1 inch = 2.54 cm
*/

#define IN2CM 2.54

int main()
{
    // prompt the user
    printf("Please enter the value in (inch):\n");
    float inchVal;
    scanf("%f", &inchVal);

    // convert and print
    float cmVal = inchVal * IN2CM;
    printf("The value in (cm) is:\n%f (cm)\n", cmVal);

    return 0;
}
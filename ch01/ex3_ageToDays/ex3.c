#include <stdio.h>
#include <string.h> // %s in printf
#include <time.h>   // localtime

/* prompt the user to enter the birthday, then print
    the age converted to days lived.
*/

int calcDays(const int, const int, const int);

int main()
{
    // prompt user for the birthday
    printf("Please enter your birthday, in the format of 'year month day':\n");
    int bYear;
    int bMonth;
    int bDay;
    scanf("%i %i %i", &bYear, &bMonth, &bDay);
    // calculate the days lived.
    int daysLived = calcDays(bYear,bMonth,bDay);
    printf("You have (roughly) lived %i days of your life.\n", daysLived);

    return 0;
}

int calcDays(const int bYear, const int bMonth, const int bDay)
{
    // get today's date
    time_t t = time(NULL);
    struct tm timeStruct = *localtime(&t);
    int curYear = timeStruct.tm_year + 1900;
    int curMonth = timeStruct.tm_mon;
    int curDay = timeStruct.tm_mday;
    // calculate days lived
    // exceptions
    if (bYear > curYear){
        printf("Oops, you are either not born yet or from the future.\n");
        return -1;
    } else if (bYear == curYear) {
        if (bMonth > curMonth) {
            printf("Oops, you are either not born yet or from the future.\n");
            return -1;
        } else if (bMonth == curMonth) {
            if (bDay > curDay) {
                printf("Oops, you are either not born yet or from the future.\n");
                return -1;
            }
        }
    }
    // normal cases
    int daysFromYear = (curYear - bYear) * 365;
    int daysFromMonth = (curMonth - bMonth) * 30; // roughly
    int daysFromDay = (curDay - bDay) * 1;
    return (daysFromYear + daysFromMonth + daysFromDay);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_count;

void rollDice(int sets, int sides, int dice)
{
    printf("Here are %d sets of %d %d-sided dice rolls: ", sets, dice, sides);
    srand(time(NULL));
    int sum;
    for (int i = 0; i < sets; i++){
        sum = 0;    // reset sum
        for (int j = 0; j < dice; j++){
            sum += rand() % sides + 1;
        }
        printf("%d  ", sum);
    }
    roll_count++;
}
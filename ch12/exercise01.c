// C Primer Plus
// Chapter 12 Exercise 1:

// Rewrite the program in Listing 12.4 so that it does not use global variables.

/* global.c -- uses an external variable */
#include <stdio.h>
// int units = 0; /* an external variable */
int critic(void);
int main(void)
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while ( units != 56)
		units = critic();
	printf("You must have looked it up!\n");
	return 0;
}
int critic(void)
{
	/* optional redeclaration omitted */
	int units;
	printf("No luck, chummy. Try again.\n");
	scanf("%d", &units);
	return units;
}

// #include <stdio.h>

// void critic(int *units);

// int main(void)
// {
// 	int units; /* an optional redeclaration */
	
// 	printf("How many pounds to a firkin of butter?\n");
// 	scanf("%d", &units);
// 	while (units != 56)
// 		critic(&units);
// 	printf("You must have looked it up!\n");
	
// 	return 0;
// }

// void critic(int *units) {
// 	printf("No luck, my friend. Try again.\n");
// 	scanf("%d", units);
// }
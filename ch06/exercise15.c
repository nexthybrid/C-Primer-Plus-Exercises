// C Primer Plus
// Chapter 6 Exercise 15:

// Write a program that reads in a line of input and then prints the line in
// reverse order. You can store the input in an array of char; assume that the
// line is no longer than 255 characters. Recall that you can use scanf() with
// the %c specifier to read a character at a time from input and that the newline
// character (\n) is generated when you press the Enter key.

#include <stdio.h>
#include <string.h> // strlen
#define STR_LEN_MAX 255

/* TIP: best practice for reading in a line from user:
	Try to avoid using scanf for buffer overflow
	If you have to use scanf, use the conversion specifier [^\n]
	to match all contents before a '\n' is detected.
*/

void reversePrintStr(char str[STR_LEN_MAX])
{
	int len = strlen(str);
	for (int i = len; i >= 0; i--)
		printf("%c",str[i]);
	printf("\n");
}

int main()
{
	printf("Please provide a sentence:\n");
	char str[STR_LEN_MAX];
	// scanf("%[^\n]%*c", str); // or scanf("%[^\n]s", str);
	scanf("%[^\n]s", str);
	printf("The input sentence is:\n");
	printf("%s\n", str);
	printf("The reverse sentence is:\n");
	reversePrintStr(str);

	return 0;

}

// #include <stdio.h>

// int main(void)
// {
// 	char line[255];
// 	int i = 0; // array index
// 	printf("Enter a line to reverse:\n");
// 	while (scanf("%c", &line[i]), line[i] != '\n')
// 		i++;

// 	for (; 0 <= i; i--) // previous loop leaves i in right position
// 		printf("%c", line[i]);

// 	printf("\n");

// 	return 0;
// }

/* C Primer Plus

Chapter 4 Exercise 5:

Write a program that requests the download speed in megabits per second (Mbs)
and the size of a file in megabytes (MB). The program should calculate the
download time for the file. Note that in this context one byte is eight bits.
Use type float, and use / for division. The program should report all three
values (download speed, file size, and download time) showing two digits to the
right of the decimal point, as in the following:

 > At 18.12 megabits per second, a file of 2.20 megabytes downloads in 0.97 seconds. */

#include <stdio.h>
#include <string.h>	// strlen

int main()
{
	// prompt user for first and last name
	printf("What is your first and last name?\n");
	char first[20];
	char last[20];
	scanf("%s %s", first, last);
	// print in aligned format
	int lenF = strlen(first);
	int lenL = strlen(last);
	printf("%*s%*s\n", lenF, first, (lenL + 3), last);
	printf("%*i%*i\n", lenF, lenF, (lenL + 3), lenL);
	// left aligned
	printf("%-*s%-*s\n", lenF + 3, first, lenL, last);
	printf("%-*i%-*i\n", lenF + 3, lenF, lenL, lenL);

	return 0;
}



// #include <stdio.h>

// int main(void)
// {
// 	const float BITS_PER_BYTE = 8;
// 	float download_speed_Mps;
// 	float file_size_MB;

// 	printf("Enter the download speed (in megabits/second): ");
// 	scanf("%f", &download_speed_Mps);
// 	printf("Enter the file size (in megabytes): ");
// 	scanf("%f", &file_size_MB);
// 	printf("At %.2f megabits per second, a file of %.2f megabytes"
// 		   " downloads in %.2f seconds.\n", download_speed_Mps, file_size_MB,
// 		   file_size_MB * BITS_PER_BYTE / download_speed_Mps);

// 	return 0;
// }

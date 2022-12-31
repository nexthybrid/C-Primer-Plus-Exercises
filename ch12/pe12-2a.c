#include <stdio.h>

static int mode;    // automatically initialized to 0
static double distance; // automatically initialized to 0
static double fuel; // automatically initialized to 0

//set_mode: set the unit mode
void set_mode(int newMode)
{
    extern int mode;
    if (newMode != 0 && newMode != 1){
        printf("Invalid mode specified. Mode 1 (US) used.");
        mode = 1;
    } else
        mode = newMode;
}

// get_info: prompts for data according to mode setting
void get_info()
{
    extern int mode;    // (optional) re-declaration
    extern double distance;
    extern double fuel;
    // prompts for distance and fuel
    if (mode == 0){
        printf("\nEnter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("\nEnter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    } else if (mode == 1){
        printf("\nEnter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("\nEnter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    } else
        printf("\nWrong mode selected.");
}

// show_info: calculates and dispalys the fuel consumption based on mode
void show_info()
{
    extern int mode;
    extern double distance;
    extern double fuel;
    double consumption;
    if (mode == 0){
        consumption = fuel / distance * 100.0;
        printf("Fuel consumption is %.2lf liters per 100 km.\n", consumption);
    } else if (mode == 1){
        consumption = distance / fuel;
        printf("Fuel consumption is %.1lf miles per gallon.\n", consumption);
    }
}
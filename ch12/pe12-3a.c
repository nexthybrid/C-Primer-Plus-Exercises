#include <stdio.h>

// get_info: prompts for data according to mode setting
void get_info(int * p_mode, double * p_distance, double * p_fuel)
{
    // prompts for distance and fuel
    if (*p_mode == 0){
        printf("\nEnter distance traveled in kilometers: ");
        scanf("%lf", p_distance);
        printf("\nEnter fuel consumed in liters: ");
        scanf("%lf", p_fuel);
    } else if (*p_mode == 1){
        printf("\nEnter distance traveled in miles: ");
        scanf("%lf", p_distance);
        printf("\nEnter fuel consumed in gallons: ");
        scanf("%lf", p_fuel);
    } else
        printf("\nWrong mode selected.\n");
}

// show_info: calculates and dispalys the fuel consumption based on mode
void show_info(int * p_mode, double * p_distance, double * p_fuel)
{
    double consumption;
    if (*p_mode == 0){
        consumption = *p_fuel / *p_distance * 100.0;
        printf("Fuel consumption is %.2lf liters per 100 km.\n", consumption);
    } else if (*p_mode == 1){
        consumption = *p_distance / *p_fuel;
        printf("Fuel consumption is %.1lf miles per gallon.\n", consumption);
    }
}
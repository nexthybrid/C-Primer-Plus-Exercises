#include <stdio.h>

int main()
{
    printf("*****************************************************************************************\n");
    printf("Create a enum of company names and look up the company index using enum\n");
    printf("*****************************************************************************************\n");

    enum company_names {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
    printf("The enum is created with valid values for GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT.\n");
    printf("Now the indices for XEROX,GOOGLE, and EBAY are:\n");
    enum company_names xrx = XEROX;
    enum company_names ggl = GOOGLE;
    enum company_names eby = EBAY;
    printf("%i, %i, %i\n",xrx,ggl,eby);

    return 0;
}
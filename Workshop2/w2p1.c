/*///////////////////////////////////////////////////////////////////////////
                              Reflection
                          Workshop - #2 (P1)
Full Name  : Aryan Tuwar
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    //variables
    double smallprice, mediumprice, largeprice;
    int no_of_shirts, total, subtotal, tax;

    //output
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallprice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumprice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeprice);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallprice);
    printf("MEDIUM : $%.2lf\n", mediumprice);
    printf("LARGE  : $%.2lf\n", largeprice);
    printf("\n");
    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &no_of_shirts);
    printf("\n");

    subtotal = smallprice * 100 * no_of_shirts;
    tax = subtotal * TAX + 0.5;
    total = subtotal + tax;
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", no_of_shirts);
    printf("Sub-total: $%8.4lf\n",  ((double) subtotal) / 100);
    printf("Taxes    : $%8.4lf\n",  ((double) tax) / 100);
    printf("Total    : $%8.4lf\n",  ((double) total) / 100);

    return 0;
}
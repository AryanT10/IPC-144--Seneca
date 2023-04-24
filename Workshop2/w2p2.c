/*///////////////////////////////////////////////////////////////////////////
                              Reflection
                          Workshop - #2 (P2)
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

int main() 
{
    //variables
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    const double TAX = 0.13;

    //variables
    double smallShirtPrice, mediumShirtPrice, largeShirtPrice;
    int numberOfShirtsPatty, numberOfShirtsTommy, numberOfShirtsSally, subTotalPatty, taxCalcPatty, totalPatty, taxCalcSally;
	int subTotalSally, totalSally, subTotalTommy, taxCalcTommy, totalTommy;
	int finalSubTotal, finaltax, finaltotal;
    

    //output
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallShirtPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumShirtPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeShirtPrice);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallShirtPrice);
    printf("MEDIUM : $%.2lf\n", mediumShirtPrice);
    printf("LARGE  : $%.2lf\n\n", largeShirtPrice);

    // Pattys Info
    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirtsPatty);
    printf("\n");

    subTotalPatty = smallShirtPrice * 100 * numberOfShirtsPatty;
    taxCalcPatty = subTotalPatty * TAX + 0.5;
    totalPatty = subTotalPatty + taxCalcPatty;

    // Tommy Info
    printf("Tommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numberOfShirtsTommy);
    printf("\n");

    subTotalTommy = largeShirtPrice * 100 * numberOfShirtsTommy;
    taxCalcTommy = subTotalTommy * TAX + 0.5;
    totalTommy = subTotalTommy + taxCalcTommy;

    // Sallys info
    printf("Sally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numberOfShirtsSally);
    printf("\n");

    subTotalSally = mediumShirtPrice * 100 * numberOfShirtsSally;
    taxCalcSally = subTotalSally * TAX + 0.5;
    totalSally = subTotalSally + taxCalcSally;

    // table
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirtPrice, numberOfShirtsPatty, (subTotalPatty + 0.0) / 100, (taxCalcPatty + 0.0) / 100, (totalPatty + 0.0) / 100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirtPrice, numberOfShirtsSally,(subTotalSally + 0.0) / 100, (taxCalcSally + 0.0) / 100, (totalSally + 0.0) / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirtPrice, numberOfShirtsTommy, (subTotalTommy + 0.0) / 100, (taxCalcTommy + 0.0) / 100, (totalTommy + 0.0) / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
   
    // final values
    finalSubTotal = (subTotalPatty + subTotalSally  +subTotalTommy);
    finaltax = taxCalcPatty + taxCalcSally + taxCalcTommy;
    finaltotal = totalPatty + totalSally + totalTommy;

    printf("                         %8.4lf  %8.4lf  %8.4lf\n", finalSubTotal / 100.0, finaltax / 100.0, finaltotal / 100.0);
    printf("\n");

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", finalSubTotal/100.0);
    printf("Toonies  %3d %9.4lf\n", finalSubTotal / 200, (finalSubTotal % 200) / 100.0);
    finalSubTotal %= 200;
    printf("Loonies  %3d %9.4lf\n", finalSubTotal / 100, (finalSubTotal % 100) / 100.0);
    finalSubTotal %= 100;
    printf("Quarters %3d %9.4lf\n", finalSubTotal / 25, (finalSubTotal % 25) / 100.0);
    finalSubTotal %= 25;
    printf("Dimes    %3d %9.4lf\n", finalSubTotal / 10, (finalSubTotal % 10) / 100.0);
    finalSubTotal %= 10;
    printf("Nickels  %3d %9.4lf\n", finalSubTotal / 5, (finalSubTotal % 5) / 100.0);
    finalSubTotal %= 5;
    printf("Pennies  %3d %9.4lf\n\n", finalSubTotal / 1, (finalSubTotal % 1) / 100.0);
    finalSubTotal %= 1;



    printf("Average cost/shirt: $%.4lf\n\n", ((subTotalPatty + subTotalSally + subTotalTommy) / 100.0)/ (numberOfShirtsPatty + numberOfShirtsSally + numberOfShirtsTommy));



    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", finaltotal / 100.0);
    printf("Toonies  %3d %9.4lf\n", finaltotal / 200, (finaltotal % 200) / 100.0);
    finaltotal %= 200;
    printf("Loonies  %3d %9.4lf\n", finaltotal / 100, (finaltotal % 100) / 100.0);
    finaltotal %= 100;
    printf("Quarters %3d %9.4lf\n", finaltotal / 25, (finaltotal % 25) / 100.0);
    finaltotal %= 25;
    printf("Dimes    %3d %9.4lf\n", finaltotal / 10, (finaltotal % 10) / 100.0);
    finaltotal %= 10;
    printf("Nickels  %3d %9.4lf\n", finaltotal / 5, (finaltotal % 5) / 100.0);
    finaltotal %= 5;
    printf("Pennies  %3d %9.4lf\n\n", finaltotal / 1, (finaltotal % 1) / 100.0);
    finaltotal %= 1;

    
    printf("Average cost/shirt: $%2.4f\n", ((totalPatty + totalSally + totalTommy) / 100.0) / (numberOfShirtsPatty + numberOfShirtsSally + numberOfShirtsTommy));
    printf("\n");
    return 0;
}
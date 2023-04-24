/******************************************************************************
                          Workshop - #6 (P1)
Full Name  : ARYAN TUWAR
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ITEMS 10
int main(void)
{
    double monthlyIncome,totalCost=0;
    int wishList,j,i;
    const double min_cost = 100.00;
   
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");
    //Monthly income and errors
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < 500.00) 
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }

        if (monthlyIncome > 400000.00)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }

        printf("\n");
    }
    while(!(monthlyIncome >= 500.00 && monthlyIncome <= 400000.00));
   
    // wish list and errors
   do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wishList);

        if (!(wishList > 0 && wishList <= MAX_ITEMS)) 
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

        printf("\n");
    }
    while(!(wishList > 0 && wishList <= MAX_ITEMS));

    double cost[wishList];
    int need[wishList];
    char finance[wishList];
    // item details (item 1 , item 2 , item 3 ...) and errors
    for (i = 1; i <= wishList; i++)
    {
        printf("Item-%d Details:\n", i);

        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);

            if (cost[i - 1] < min_cost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            } 
        }
        while (cost[i - 1] < min_cost);
    // Need for the item and errors
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &need[i - 1]);

            if ((need[i - 1] < 1) || (need[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            } 
        }
        while ((need[i - 1] < 1) || (need[i - 1] > 3));
    // Financing and errors
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i - 1]);

            if (!(finance[i - 1] == 'n' || finance[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } 
        }
        while (!(finance[i - 1] == 'n' || finance[i - 1] == 'y'));
        printf("\n");
    }

    // Summary with table
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    for(j = 1; j <= wishList; j++)
    {
    printf("  %d      %d        %c     %10.2lf\n", j, need[j - 1], finance[j - 1], cost[j - 1]);
    totalCost += cost[j - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n", totalCost);
    printf("\n");
    //Ending statement
    printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}

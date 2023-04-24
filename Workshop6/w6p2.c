/******************************************************************************
                          Workshop - #6 (P2)
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
    // variables
    double monthlyIncome, totalCost = 0;
    const double minCost = 100.00;
    int wishList, selection, j, i, loopContinue = 1;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

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

    //declared arrays !!
    double cost[wishList];
    int priority[wishList];
    char financeOption[wishList];

     for (i = 1; i <= wishList; i++)
    {
        printf("Item-%d Details:\n", i);
        //cost and errors
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);

            if (cost[i - 1] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            } 
        }
        while (cost[i - 1] < minCost);

        //priority and errors
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            } 
        }
        while ((priority[i - 1] < 1) || (priority[i - 1] > 3));
        //financing and error
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i - 1]);

            if (!(financeOption[i - 1] == 'n' || financeOption[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } 
        }
        while (!(financeOption[i - 1] == 'n' || financeOption[i - 1] == 'y'));

        printf("\n");
    }

    // Summary table
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    // Using iteration
    for(j = 1; j <= wishList; j++)
    {
        printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1], financeOption[j - 1], cost[j - 1]);
        totalCost += cost[j - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %10.2lf\n", totalCost);
    printf("\n");

    // Displaying menu 
    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");

        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");

		// variables
		int item, note = 0;
		int priorityFilter, k;
        double costOfPriorityItems = 0, year, months, remainingMonths;

        if (selection == 0) {
            loopContinue = 0;
        }

        else if (selection == 1) {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);

            // year and months
            months = (totalCost / monthlyIncome) + 0.5;
            year = ((int) months) / 12;
            remainingMonths = (months - (year * 12)) + 0.5;

            printf("Forecast: %d years, %d months\n", (int) year, (int) remainingMonths);

            // for loop 
            note = 0;
            for (item = 0; item < wishList; item++)
            {
                if (financeOption[item] == 'y') {
                    note += 1;
                }
            }
            if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            printf("\n");
        }
        // priority filter
        else if (selection == 2) {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);
            printf("\n");

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityFilter);
            for (k = 0; k < wishList; k++)
            {
                if (priority[k] == priorityFilter) {
                    costOfPriorityItems += cost[k];
                }
            }

            // year and months
            months = (costOfPriorityItems / monthlyIncome) + 0.5; 
            year = ((int) months) / 12;
            remainingMonths = (months - (year * 12)) + 0.5; 

            printf("Amount:   $%.2lf\n", costOfPriorityItems);
            printf("Forecast: %d years, %d months\n", (int) year, (int) remainingMonths);

            // for loop
            // Selection of financing and error
            note = 0;
            for (item = 0; item < wishList; item++)
            {
                if (financeOption[item] == 'y' && priority[item] == priorityFilter) {
                    note += 1;
                }
            }
            if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            printf("\n");
        }

        else if (selection < 0 || selection > 2) {
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
        }

    }
    while(loopContinue == 1);

    // End
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}

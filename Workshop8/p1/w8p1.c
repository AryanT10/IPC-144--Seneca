/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : ARYAN TUWAR
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr1)
{
      int userInput;
         do{
			 scanf("%d", &userInput);
			 if(userInput <=0)
			 {
				 printf("ERROR: Enter a positive value: ");
			 }
		 } while (userInput <= 0);
		 if (intPtr1 != NULL)
		 {
			 *intPtr1 = userInput;
		  }
		  return userInput;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePtr1)
{
      double userInput;
         do{
			 scanf("%lf", &userInput);
			 if(userInput <=0)
			 {
				 printf("ERROR: Enter a positive value: ");
			 }
		 } while (userInput <= 0);
		 if (doublePtr1 != NULL)
		 {
			 *doublePtr1 = userInput;
		  }
		  return userInput;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfSequence)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n", NUM_OF_GRAMS);
	printf("\n");
}

// 4. Get user input for the details of cat food product
   // CAT FOOD INFORMATION
    struct CatFoodInfo getCatFoodInfo(const int numberOfSequence) 
	{
    struct CatFoodInfo catFoodI;
    int flag;
    printf("Cat Food Product #%d\n", numberOfSequence + 1);
    printf("--------------------\n");
    flag=1;
    printf("SKU           : ");
do {
		scanf("%d", &catFoodI.skuNumber);
		if (catFoodI.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		} 
	} while (flag);
    //PRICE
    printf("PRICE         : $");
    flag = 1;
	do {
		scanf("%lf", &catFoodI.productPrice);
		if (catFoodI.productPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		} 
	} while (flag);

    //WEIGHT
    printf("WEIGHT (LBS)  : ");
    flag = 1;
	do {
		scanf("%lf", &catFoodI.productWeight);
		if (catFoodI.productWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		} 
	} while (flag);

    //CALORIES
    printf("CALORIES/SERV.: ");
    flag = 1;
	do {
		scanf("%d", &catFoodI.caloriesPerServe);
		if (catFoodI.caloriesPerServe <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		} 
	} while (flag);    
     //END
	printf("\n");
	return catFoodI;
	}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int skuNumber, double* productPrice, double*productWeight, int caloriesPerServe) 
{
    printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeight, caloriesPerServe);
}

// 7. Logic entry point
/**
 * Start the cat food program.
 */
/**
 * Start the cat food application.
 */
    void start(void) {
    const int numProducts = MAX_PRODUCT;
    struct CatFoodInfo catFoodI[numProducts];
    int i = 0;
    openingMessage(numProducts);

    for(i = 0; i < numProducts; i++){
        catFoodI[i] = getCatFoodInfo(i);
    }
     i = 0;
    displayCatFoodHeader();

    for(i = 0; i < numProducts; i++){
        displayCatFoodData(catFoodI[i].skuNumber, &(catFoodI[i].productPrice), &(catFoodI[i].productWeight), catFoodI[i].caloriesPerServe);
    }
}


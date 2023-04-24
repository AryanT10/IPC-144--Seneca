/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
    int getIntPositive(int* resultint)
	{
		int valueint=0;
    	do {
        	scanf("%d", &valueint);
       	 	if (valueint <= 0) {
            	printf("ERROR: Enter a positive value: ");
       	 	}
    	} while (valueint <= 0);

		if (resultint != NULL) {
        	*resultint = valueint;
    	}
    	return valueint;
	}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
    double getDoublePositive(double* resultdouble)
	{
		double valuedouble=0;
		do
		{
        	scanf("%lf", &valuedouble);
       	 	if (valuedouble <= 0) {
            	printf("ERROR: Enter a positive value: ");
       	 	}
		} while (valuedouble <=0);
		if (resultdouble != NULL) {
        	*resultdouble = valuedouble;
    	}
    	return valuedouble;

	}

// 3. Opening Message (include the number of products that need entering)
    const int OpeningMessage(const int i)
	{


		printf("Cat Food Cost Analysis\n");	
		printf("======================\n\n");	

		printf("Enter the details for %d dry food bags of product data for analysis.\n", i);
		printf("NOTE: A \'serving\' is %dg\n\n", SERVING);
		return i;
	}

// 4. Get user input for the details of cat food product
    struct CatFoodInfo getCatFoodInfo(const int product)
{
	struct CatFoodInfo foods;
	 printf("Cat Food Product #%d\n", product + 1);
    printf("--------------------\n");
	
    int flag=1;
    printf("SKU           : ");
do {
		scanf("%d", &foods.skuNumber);
		if (foods.skuNumber <= 0)
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
		scanf("%lf", &foods.productPrice);
		if (foods.productPrice <= 0)
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
		scanf("%lf", &foods.productWeight);
		if (foods.productWeight <= 0)
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
		scanf("%d", &foods.calories);
		if (foods.calories <= 0)
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
	return foods;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

    void displayCatFoodData( int skuNumber, double* productPrice, int calories, double* productWeight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeight, calories);
}
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg( double* lbs, double* kgconvert)
{
    double kg = *lbs/LBS_TO_KG ; 

    if (kgconvert != NULL) { 
        *kgconvert = kg;
    }

    return kg; //result
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double* lbs, int*gramconvert){
    
    double lb = *lbs;
    int gram = convertLbsKg(&lb, NULL)*1000;
        

    if (gramconvert != NULL)
    {
        *gramconvert = gram; 
    }
    return gram;

}


// 10. convert lbs: kg and g
void convertLbs(double* lbs, double* kgs, int* gram)
{
        double resultkg;
        int resultgram;

        double lb = *lbs;
        resultkg = convertLbsKg(&lb,NULL);
        resultgram = convertLbsG(&lb,NULL);

        if (kgs != NULL && gram != NULL)
        {
            *kgs = resultkg;
            *gram = resultgram;
        }
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int weightGram, double* servings){
        double serve = ((double)weightGram/gPerServ);

        if (servings != NULL)
        {
            *servings = serve;
        }
    return serve;     
}

// 12. calculate: cost per serving
    double calculateCostPerServing(const double price, const double totalServings, double* costPerServe){
            double cost = price/totalServings;
          if (costPerServe != NULL)
            {
            *costPerServe = cost;
            }
            return cost;   
    }

// 13. calculate: cost per calorie
    double calculateCostPerCal(const double price, const double totalCalories, double* costPerCalories){
        double costCalories = price / totalCalories;
         if (costPerCalories != NULL)
            {
            *costPerCalories = costCalories;
            }
            return costCalories;
    }
        

// 14. Derive a reporting detail record based on the cat food product data

    struct ReportData calculateReportData(struct CatFoodInfo foods){
        struct ReportData report;

        report.skuNum = foods.skuNumber;
        report.productPrice2= foods.productPrice;
        report.productWeightLb= foods.productWeight;
        report.productCalories= foods.calories;
        report.totalServing = calculateServings(SERVING,convertLbsG(&foods.productWeight,&report.productWeightGrams), &report.totalServing);
        report.costPerServe = calculateCostPerServing(report.productPrice2, report.totalServing, &report.costPerServe);
        report.caloriePerServe = calculateCostPerCal(report.costPerServe, foods.calories,&report.caloriePerServe);
        report.productWeightKg = convertLbsKg(&foods.productWeight, &report.productWeightKg);
        report.productWeightGrams= convertLbsG(&foods.productWeight, &report.productWeightGrams);
    
        return report;
    }

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
        printf("\n");
	printf("Analysis Report (Note: Serving = %dg)\n", SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

    void displayReportData(const struct ReportData display, const int cheapest){
        int flag=0;

        if (flag == cheapest)
        {
            printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n",
            display.skuNum,display.productPrice2,display.productWeightLb,display.productWeightKg, display.productWeightGrams, display.productCalories, display.totalServing, display.costPerServe, display.caloriePerServe);
        }
        else
        {
            printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",display.skuNum,display.productPrice2,display.productWeightLb,display.productWeightKg, display.productWeightGrams, display.productCalories, display.totalServing, display.costPerServe , display.caloriePerServe);
            
        }
    }
    
// 17. Display the findings (cheapest)
    void displayFinalAnalysis(int skuNum, double productPrice2){
        printf("\nFinal Analysis");
        printf("\n--------------");
        printf("\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:00%d Price: $%.2lf\n\nHappy shopping!\n", skuNum, productPrice2);
    }

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo food[MAXPRODUCT] = {{0}};
    int productNumber = 3, j=0;
    OpeningMessage(productNumber);

    for ( j = 0; j < productNumber; j++)
    {
        food[j] = getCatFoodInfo(j);
    }

    displayCatFoodHeader();
    
    for ( j = 0; j < productNumber; j++)
    {
			displayCatFoodData(food[j].skuNumber, &(food[j].productPrice), food[j].calories, &(food[j].productWeight));
        
    }

    struct ReportData report[MAXPRODUCT]= {{0}};

    for ( j = 0; j < productNumber; j++)
    {
        report[j]=calculateReportData(food[j]);
    }

    displayReportHeader();

    int x,y;

    for ( j = 0; j < productNumber; j++)
    {
        for ( x = 0; x < productNumber; x++)
        {
            if (report[j].costPerServe > report[x].costPerServe)
            {
                y=x;
            }
            
        }

        x=0;
    }
    for ( j = 0; j < productNumber; j++)
    {
        if (j != 0)
        {
            displayReportData(report[j], y-j);
        }
        else
        {
            displayReportData(report[j], y);
        }
        
    }
    
    displayFinalAnalysis(report[y].skuNum, report[y].productPrice2);
}

/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
	
	int bagWeight1, bagWeight2, bagWeight3,dailyServe1,dailyServe2;
	char type1, type2, type3, type4,type5;
	char servedWithCream1, servedWithCream2, servedWithCream3, servedWithCream4,servedWithCream5;
	printf("Take a Break - Coffee Shop");
	printf("\n==========================\n");

	printf("\nEnter the coffee product information being sold today...\n");
	
//COFFEE1
		printf("\nCOFFEE-1...");
		printf("\nType ([L]ight,[M]edium,[R]ich): ");
		scanf(" %c", &type1);
		fflush(stdin);
		printf("Bag weight (g): ");
		scanf(" %d", &bagWeight1);
		fflush(stdin);
		printf("Best served with cream ([Y]es,[N]o): ");
		scanf(" %c", &servedWithCream1); 
		fflush(stdin);


//COFFEE2
	 	printf("\nCOFFEE-2...");
	 	printf("\nType ([L]ight,[M]edium,[R]ich): ");
	 	scanf(" %c", &type2);
		fflush(stdin);
		printf("Bag weight (g): ");
		scanf(" %d", &bagWeight2);
		fflush(stdin);
	 	printf("Best served with cream ([Y]es,[N]o): ");
		scanf(" %c", &servedWithCream2);
		fflush(stdin);


		 	printf("\nCOFFEE-3...");
			printf("\nType ([L]ight,[M]edium,[R]ich): ");
			scanf(" %c", &type3);
			fflush(stdin);
			printf("Bag weight (g): ");
		 	scanf(" %d", &bagWeight3);
			fflush(stdin);
			printf("Best served with cream ([Y]es,[N]o): ");
			scanf(" %c", &servedWithCream3);
			fflush(stdin);
		 	printf("\n");

			printf("---+------------------------+---------------+-------+");
			printf("\n   |    Coffee              |   Packaged    | Best  |");
			printf("\n   |     Type               |  Bag Weight   | Served|");
			printf("\n   +------------------------+---------------+ With  |");
			printf("\nID | Light | Medium | Rich  |  (G) | Lbs    | Cream |");
			printf("\n---+------------------------+---------------+-------|");
			printf("\n 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type1 == 'l' || type1 == 'L', type1 == 'm' || type1 == 'M', type1 == 'R' || type1 == 'r', bagWeight1, bagWeight1 / GRAMS_IN_LBS, servedWithCream1 == 'y' || servedWithCream1 == 'Y');
			printf("\n 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'R' || type2 == 'r', bagWeight2, bagWeight2 / GRAMS_IN_LBS, servedWithCream2 == 'y' || servedWithCream2 == 'Y');
                        printf("\n 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type3 == 'l' || type3 == 'L', type3 == 'm' || type3 == 'M', type3 == 'R' || type3 == 'r', bagWeight3, bagWeight3 / GRAMS_IN_LBS, servedWithCream3 == 'y' || servedWithCream3 == 'Y');


			printf("\n\nEnter how you like your coffee...");
			printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
			scanf(" %c", &type4);
			fflush(stdin);
			printf("Do you like your coffee with cream ([Y]es,[N]o): ");
			scanf(" %c", &servedWithCream4);
			fflush(stdin);
			printf("Typical number of daily servings: ");
			scanf(" %d", &dailyServe1);
			fflush(stdin);

			printf("\nThe below table shows how your preferences align to the available products:\n");

            printf("\n--------------------+-------------+-------+");
			printf("\n  |     Coffee      |  Packaged   | With  |");
			printf("\nID|      Type       | Bag Weight  | Cream |");
			printf("\n--+-----------------+-------------+-------+");
			printf("\n 1|       %d         |      %d      |   %d   |",type4==type1-32 || type4==type1+32,    dailyServe1>=1&&dailyServe1<=4 ,   servedWithCream4==servedWithCream1+32||servedWithCream4==servedWithCream1-32||servedWithCream4==servedWithCream1);
			printf("\n 2|       %d         |      %d      |   %d   |",type4==type2-32 || type4==type2+32,    dailyServe1>=5&&dailyServe1<=9 ,   servedWithCream4==servedWithCream2+32||servedWithCream4==servedWithCream2-32||servedWithCream4==servedWithCream2);
			printf("\n 3|       %d         |      %d      |   %d   |",type4==type3-32 || type4==type3+32,    dailyServe1>=10,                   servedWithCream4==servedWithCream3+32||servedWithCream4==servedWithCream3-32||servedWithCream4==servedWithCream3);
        
                        printf("\n\nEnter how you like your coffee...");
		        printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
			scanf(" %c", &type5);
			fflush(stdin);
			printf("Do you like your coffee with cream ([Y]es,[N]o): ");
			scanf(" %c", &servedWithCream5);
			fflush(stdin);
			printf("Typical number of daily servings: ");
			scanf(" %d", &dailyServe2);
			fflush(stdin);

			printf("\nThe below table shows how your preferences align to the available products:\n");

            printf("\n--------------------+-------------+-------+");
			printf("\n  |     Coffee      |  Packaged   | With  |");
			printf("\nID|      Type       | Bag Weight  | Cream |");
			printf("\n--+-----------------+-------------+-------+");
			printf("\n 1|       %d         |      %d      |   %d   |",type5==type1-32||type5==type1+32||type5==type1, dailyServe2>=1&&dailyServe2<=4 ,     servedWithCream5==servedWithCream1+32||servedWithCream5==servedWithCream1-32||servedWithCream5==servedWithCream1);
			printf("\n 2|       %d         |      %d      |   %d   |",type5==type2-32||type5==type2+32||type5==type2, dailyServe2>=1&&dailyServe2<=4 ,     servedWithCream5==servedWithCream2+32||servedWithCream5==servedWithCream2-32||servedWithCream5==servedWithCream2);
			printf("\n 3|       %d         |      %d      |   %d   |",type5==type3-32||type5==type3+32||type5==type3, dailyServe2>=10,                     servedWithCream5==servedWithCream3+32||servedWithCream5==servedWithCream3-32||servedWithCream5==servedWithCream3);
			
			printf("\n\nHope you found a product that suits your likes!\n");
	return 0;
}  

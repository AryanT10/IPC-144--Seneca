/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : ARYAN TUWAR
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
	const int iD1=111, iD2=222, iD3=111;
	const char a1 = 'Y';
	const char a2 = 'N';
	const float price1 = 111.49, price2 = 222.99, price3 = 334.49;

	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)", iD1);
	printf("\n");
	printf("  Taxed: %c\n",a1);
	printf("  Price: $%2.4f",price1);
	printf("\n\n");
	printf("Product-2 (ID:%d)", iD2);
	printf("\n");
	printf("  Taxed: %c", a2);
	printf("\n");
	printf("  Price: $%2.4f\n\n", price2);
	printf("Product-3 (ID:%d)", iD3);
	printf("\n");
	printf("  Taxed: %c",a2 );
	printf("\n");
	printf("  Price: $%2.4f\n", price3);
	printf("\n");
	printf("The average of all prices is: $%.4lf", (price1 + price2 + price3) / 3);
	printf("\n");
	printf("\nAbout Relational and Logical Expressions!");
	printf("\n========================================");
	printf("\n1. These expressions evaluate to TRUE or FALSE");
	printf("\n2. FALSE: is always represented by integer value 0");
	printf("\n3. TRUE : is represented by any integer value other than 0");
	printf("\n");
	printf("\nSome Data Analysis...");
	printf("\n=====================");
	printf("\n1. Is product 1 taxable? -> %d", a1 == 'Y' ? 1 : 0);
	printf("\n");
	printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> %d", a2 == 'N' ? 1 : 0);
	printf("\n");
	printf("\n3. Is product 3 less than testValue ($%.2lf)? -> %d", testValue,a1 == 'Y' ? 0 : 1);
	printf("\n");
	printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d",price3 > (price1 + price2) ? 1 : 0);
	printf("\n");
	printf("\n5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $111.50)", price1 >= (price3 - price2) ? 1 : 0);
	printf("\n");
	printf("\n6. Is the price of product 2 equal to or more than the average price? -> %d", price2 >= (price1 + price2 + price3) / 3 ? 1 : 0);
	printf("\n");
	printf("\n7. Based on product ID, product 1 is unique -> %d", iD1 == iD3 ? 0 : 1);
	printf("\n");
	printf("\n8. Based on product ID, product 2 is unique -> %d", iD1 == iD3 ? 1 : 0);
	printf("\n");
	printf("\n9. Based on product ID, product 3 is unique -> %d", iD1 == iD3 ? 0 : 1);
	printf("\n\n");
	return 0;
}
// *****************************************************************************
//                    <assessment name example: Workshcharacter - #4 (Part-1)>
//      Full Name  :ARYAN TUWAR
//      Student ID#: 112137229
//      Email      : atuwar@myseneca.ca
//      Section    : ZCC
//      Authenticity Declaration:
//      I declare this submission is the result of my own work and has not been
//      shared with any other student or 3rd party content provider. This submitted
//      piece of work is entirely of my own creation.
//      *****************************************************************************


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void)
{
	int i=0,number;
	char character;
	printf("+----------------------+");
	printf("\nLoop application STARTED");
	printf("\n+----------------------+\n");
do
 {
	printf("\nD = do/while | W = while | F = for | Q = quit");
	printf("\nEnter loop type and the number of times to iterate (Quit=Q0): ");
	scanf(" %c%d", &character, &number);
	switch (character)
	{case 'W':
			  if (number >= 3 && number <= 20)
			 {
			   printf("WHILE   : ");
			 
				 for (i = 1; i <= number; i++)
				 {
					 printf("%c", character);
				 }
				 printf("\n");
			 }
			 else
			 {
				 printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
			 }
			 break;
		 case 'D':
			  if (number >= 3 && number <= 20)
			 {
			   printf("DO-WHILE: ");
			 
				 for (i = 1; i <= number; i++)
				 {
					 printf("%c", character);
				 }
				 printf("\n");
			 }
			 else
			 {
				 printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
			 }
			 break;
			 case 'F':
			  if (number >= 3 && number <= 20)
			 {
			   printf("FOR     : ");
			 
				 for (i = 1; i <= number; i++)
				 {
					 printf("%c", character);
				 }
				 printf("\n");
			 }
			 else
			 {
				 printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
			 }
			 break;
	    case'Q':
		if(number!=0)
		{
				 printf("ERROR: To quit, the number of iterations should be 0!\n");
		}
		break;
		default:
		printf("ERROR: Invalid entered value(s)!\n");
    }

 } while (!(character == 'Q' && number == 0));
 printf("\n+--------------------+");
 printf("\nLoop application ENDED");
 printf("\n+--------------------+");
 printf("\n\n");

 return 0;
 
}

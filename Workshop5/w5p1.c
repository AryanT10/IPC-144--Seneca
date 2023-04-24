/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
int main(void)
{
	int year=0, month=0,day=1;
	const int JAN = 1, DEC = 12;


	printf("General Well-being Log");
	printf("\n======================\n");
	do{
	printf("Set the year and month for the well-being log (YYYY MM): ");
	scanf("%d %d", &year, &month);

	if((year<MIN_YEAR || year>MAX_YEAR) && (month<JAN || month>DEC))
	{
		printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
	    printf("   ERROR: Jan.(1) - Dec.(12)");
	}
	else if(month<JAN || month>DEC)
	{
		printf("   ERROR: Jan.(1) - Dec.(12)");
		
	}
	else if(year<MIN_YEAR || year>MAX_YEAR)
	{
		printf("   ERROR: The year must be between 2012 and 2022 inclusive");
	}
	
	else
	{
		printf("\n*** Log date set! ***");
	}
	printf("\n");
  if(year>=MIN_YEAR && year <=MAX_YEAR)
  {
switch (month)
{
    case 1:
             printf("\nLog starting date: %d-JAN-0%d",year,day);
             break;
   case 2:
             printf("\nLog starting date: %d-FEB-0%d",year,day);
             break;
   case 3:
             printf("\nLog starting date: %d-MAR-0%d",year,day);
             break;
   case 4:
             printf("\nLog starting date: %d-APR-0%d",year,day);
             break;
   case 5:
             printf("\nLog starting date: %d-MAY-0%d",year,day);
             break;
   case 6:
             printf("\nLog starting date: %d-JUN-0%d",year,day);
             break;
   case 7:
             printf("\nLog starting date: %d-JUL-0%d",year,day);
             break;
   case 8:
             printf("\nLog starting date: %d-AUG-0%d",year,day);
             break;
   case 9:
             printf("\nLog starting date: %d-SEP-0%d",year,day);
             break;
   case 10:
             printf("\nLog starting date: %d-OCT-0%d",year,day);
             break;
   case 11:
             printf("\nLog starting date: %d-NOV-0%d",year,day);
             break;
   case 12:
             printf("\nLog starting date: %d-DEC-0%d",year,day);
   break;
}

  } 
} while (month < JAN || month > DEC || year<MIN_YEAR || year>MAX_YEAR);
printf("\n\n");
  return 0;
}

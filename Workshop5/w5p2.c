/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;         
    int year=0, month=0,day=0;                     
    double morningRate, eveningRate, morningRateSum = 0, eveningRateSum = 0;
    int loop = 1;

    printf("General Well-being Log");
    printf("\n======================\n");
    while (loop == 1)
    {
    printf("Set the year and month for the well-being log (YYYY MM): ");
    scanf("%d %d", &year, &month);

    if (!(year >= MIN_YEAR && year <= MAX_YEAR))
    {
    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
    }

    if (!(month >= JAN && month <= DEC))
    {
    printf("   ERROR: Jan.(1) - Dec.(12)\n");
    }

    if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
    {
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");

  for (day = 1; day <= LOG_DAYS; day++)
  {
   
    switch (month)
    {
    case 1:
          printf("%d-JAN-0%d\n", year, day);
          break;
    case 2:
          printf("%d-FEB-0%d\n", year, day);
          break;
    case 3:
          printf("%d-MAR-0%d\n", year, day);
          break;
    case 4:
          printf("%d-APR-0%d\n", year, day);
          break;
    case 5:
          printf("%d-MAY-0%d\n", year, day);
          break;
    case 6:
          printf("%d-JUN-0%d\n", year, day);
          break;
    case 7:
          printf("%d-JUL-0%d\n", year, day);
          break;
    case 8:
          printf("%d-AUG-0%d\n", year, day);
          break;
    case 9:
          printf("%d-SEP-0%d\n", year, day);
          break;
    case 10:
          printf("%d-OCT-0%d\n", year, day);
          break;
    case 11:
          printf("%d-NOV-0%d\n", year, day);
          break;
    case 12:
          printf("%d-DEC-0%d\n", year, day);
          break;
  }

   printf("   Morning rating (0.0-5.0): ");
   scanf("%lf", &morningRate);
                
   while (!(morningRate >= 0.0 && morningRate <= 5.0))
   {
    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
    printf("   Morning rating (0.0-5.0): ");
    scanf("%lf", &morningRate);
   }

    printf("   Evening rating (0.0-5.0): ");
    scanf("%lf", &eveningRate);

    while (!(eveningRate >= 0.0 && eveningRate <= 5.0))
  {
  printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
  printf("   Evening rating (0.0-5.0): ");
  scanf("%lf", &eveningRate);
 }

  morningRateSum += morningRate;
  eveningRateSum +=eveningRate;
  printf("\n");
  }

  loop = 0;
  }
  }

    //SUMMARY
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningRateSum);
    printf("Evening total rating:  %.3lf\n", eveningRateSum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", morningRateSum + eveningRateSum);
    printf("\n");

    printf("Average morning rating:  %.1lf\n", morningRateSum / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningRateSum / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", ((morningRateSum / LOG_DAYS) + (eveningRateSum / LOG_DAYS)) / 2);
    printf("\n");

    return 0;
}

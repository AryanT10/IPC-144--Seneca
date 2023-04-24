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
	int numberOfApples=0, numberOfOranges=0, numberOfPears=0, numberOfTomatoes=0, numberOfCabbages=0;
	int applesPicked=0,orangesPicked=0,cabbagesPicked=0,tomatoesPicked=0,pearsPicked=0,quit=0;

    do
	{
	printf("Grocery Shopping");
	printf("\n================");
	//APPLE
	do 
	{
		printf("\nHow many APPLES do you need? : ");
		scanf("%d", &numberOfApples);
		if(numberOfApples<0)
		{
			printf("ERROR: Value must be 0 or more.");
		}
	} while (numberOfApples<0);


	// ORANGES
	do 
	{
		printf("\nHow many ORANGES do you need? : ");
		scanf("%d", &numberOfOranges);
		if(numberOfOranges<0)
		{
			printf("ERROR: Value must be 0 or more.");
		}
	} while (numberOfOranges<0);


	// PEAR
    do 
	{
		printf("\nHow many PEARS do you need? : ");
		scanf("%d", &numberOfPears);
		if(numberOfPears<0)
		{
			printf("ERROR: Value must be 0 or more.");
		}
	} while (numberOfPears<0);


	//TOMATOES
	do 
	{
		printf("\nHow many TOMATOES do you need? : ");
		scanf("%d", &numberOfTomatoes);
		if(numberOfTomatoes<0)
		{
			printf("ERROR: Value must be 0 or more.");
		}
	} while (numberOfTomatoes<0);


	//CABBAGES
	
	do 
	{
		printf("\nHow many CABBAGES do you need? : ");
		scanf("%d", &numberOfCabbages);
		if(numberOfCabbages<0)
		{
			printf("ERROR: Value must be 0 or more.");
		}
	} while (numberOfCabbages<0);


	//PICKUP
	printf("\n--------------------------");
	printf("\nTime to pick the products!");
	printf("\n--------------------------\n\n");
   
   //PICKUP FOR APPLES
   while(numberOfApples>0)
   {
		printf("Pick some APPLES... how many did you pick? : ");
		scanf("%d", &applesPicked);
		if (applesPicked > numberOfApples)
		{
			printf("You picked too many... only %d more APPLE(S) are needed.\n", numberOfApples);
	}
	else if (applesPicked<=0)
	{
			printf("ERROR: You must pick at least 1!\n");
	}
	else {
			numberOfApples -= applesPicked;
			if (numberOfApples > 0)
			{
				printf("Looks like we still need some APPLES...\n");
			}
			else{
				printf("Great, that's the apples done!\n\n");
			}
	}
   }

//PICKUP OF PEAR
   while(numberOfPears>0)
   {
		printf("Pick some PEARS... how many did you pick? : ");
		scanf("%d", &pearsPicked);
		if (pearsPicked > numberOfPears)
		{
			printf("You picked too many... only %d more PEAR(S) are needed.\n", numberOfPears);
	}
	else if (pearsPicked<=0)
	{
			printf("ERROR: You must pick at least 1!\n");
	}
	else {
			numberOfPears -= pearsPicked;
			if (numberOfPears > 0)
			{
				printf("Looks like we still need some PEARS...\n");
			}
			else{
				printf("Great, that's the pears done!\n\n");
			}
	}
   }


   //PICKUPS OF THE CABBAGES
   while(numberOfCabbages>0)
   {
		printf("Pick some CABBAGES... how many did you pick? : ");
		scanf("%d", &cabbagesPicked);
		if (cabbagesPicked > numberOfCabbages)
		{
			printf("You picked too many... only %d more CABBAGE(S) are needed.\n", numberOfCabbages);
	}
	else if (cabbagesPicked<=0)
	{
			printf("ERROR: You must pick at least 1!\n");
	}
	else {
			numberOfCabbages -= cabbagesPicked;
			if (numberOfCabbages > 0)
			{
				printf("Looks like we still need some CABBAGES...\n");
			}
			else{
				printf("Great, that's the cabbages done!\n\n");
			}
	}
   }

   //PICKUP FOR THE ORANGES
    while(numberOfOranges>0)
   {
		printf("Pick some ORANGES... how many did you pick? : ");
		scanf("%d", &orangesPicked);
		if (orangesPicked > numberOfOranges)
		{
			printf("You picked too many... only %d more ORANGE(S) are needed.\n", numberOfOranges);
	}
	else if (orangesPicked<=0)
	{
			printf("ERROR: You must pick at least 1!\n");
	}
	else {
			numberOfOranges -= orangesPicked;
			if (numberOfOranges > 0)
			{
				printf("Looks like we still need some ORANGES...\n");
			}
			else{
				printf("Great, that's the oranges done!\n\n");
			}
	}
   }


   //PICKUP OF THE TOMATOES
   while(numberOfTomatoes>0)
   {
		printf("Pick some TOMATOES... how many did you pick? : ");
		scanf("%d", &tomatoesPicked);
		if (tomatoesPicked > numberOfTomatoes)
		{
			printf("You picked too many... only %d more TOMATO(ES) are needed.\n", numberOfTomatoes);
	}
	else if (tomatoesPicked<=0)
	{
			printf("ERROR: You must pick at least 1!\n");
	}
	else {
			numberOfTomatoes -= tomatoesPicked;
			if (numberOfTomatoes > 0)
			{
				printf("Looks like we still need some TOMATOES...\n");
			}
			else{
				printf("Great, that's the tomatoes done!\n\n");
			}
	}
   }
   printf("All the items are picked!\n");
   printf("\nDo another shopping? (0=NO): ");
   scanf("%d", &quit);
   printf("\n");
	} while (quit != 0);

	printf("Your tasks are done for today - enjoy your free time!\n");
	return 0;
}

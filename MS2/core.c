/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <ctype.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Used to return an integer value and recieve no arguments . An invalid value will show an error message.
int inputInt(void) 
{
    char character = ' ';
    int value;
    int validInput = 0; // initialize stop to false

    while (!validInput) { // keep looping until input is valid
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } else {
            validInput = 1; // set stop to true
        }
    }
    return value;
}

// Read a positive integer value from user input. A zero or invalid value will show an error message.
int inputIntPositive(void) 
{
    char character = ' ';
    int value;
    int stop = 1;

    while (stop) {
        if (scanf("%d%c", &value, &character) != 2 || character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
        else {
            stop = 0;
        }
    }
    return value;
}

// Read an integer value from user input within a specified range. An invalid value will show an error message and continue until the entered value is in range.
int inputIntRange(int lowerBound, int upperBound) 
{
    char character = ' ';
    int value2, validInput = 0;

    while (!validInput) {
        if (scanf("%d%c", &value2, &character) != 2 || character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (value2 < lowerBound || value2 > upperBound) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
        else {
            validInput = 1;
        }
    }
    return value2;
}

// Read a single character from user input and validate it against a list of valid characters. If character is not in the list of valid characters it will show an error message.
char inputCharOption(char str[]) {
    int i, count;
    char input;
    int foundOption;

    do {
        count = 0;
        foundOption = 0;
        scanf(" %c", &input);

        for (i = 0; str[i] != '\0'; i++) {
            if (input == str[i]) {
                count++;
                foundOption = 1;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (!foundOption);

    // After all checks are passed we will return the input value
    clearInputBuffer();
    return input;
}

// Read a C string value from user input and validate that it contains a number of characters within the range of character specified by the 2nd and 3rd arguments received.
void inputCString(char str[], int minimum, int maximum) 
{
    int stop = 1;
    char ch = ' ';
	int length = 0;

    while (stop) {
        length = 0;

        // Takes a string as input until it sees a newline character
        while (ch != '\n' && length <= maximum) {
            ch = getchar();
			str[length] = ch;
			length++;
        }

        // If the string is less than or equal to the maximums we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && length <= (maximum + 1)) {
            length--;
            str[length] = '\0';
        }
        // If length is more than maximum, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maximum] = '\0';
            clearInputBuffer();
        }

        if (minimum == maximum && length != minimum) {
            printf("ERROR: String length must be exactly %d chars: ", minimum);
            ch = 'a';
        }
        else if (length < minimum || length > maximum) {
            if (length > maximum) {
                printf("ERROR: String length must be no more than %d chars: ", maximum);
                ch = 'a';
            }
            else if (length < minimum) {
                printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
                ch = 'a';
            }
        }
        else {
            stop = 0;
        }
    }
}

// Display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* str) 
{
     int length = 0, i;
     while (str != NULL && str[length] && isdigit(str[length])) {
     length++;
    }
     if (length == 10) 
	{
     i = 0;
     printf("(");
     while (i < 3) 
	{
         printf("%c", str[i]);
         i++;
    }
    printf(")");
    while (i < 6) 
	{
        printf("%c", str[i]);
        i++;
    }
    printf("-");
    while (i < 10) 
	{
        printf("%c", str[i]);
        i++;
    }
    }
     else 
	 {
     printf("(___)___-____");
     }
      if (str != NULL) 
  {
      for (i = 0; str[i] != '\0'; i++)
      length++;
  }
}

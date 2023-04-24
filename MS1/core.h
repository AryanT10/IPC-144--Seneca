/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

// Used to return an integer value and recieve no arguments . An invalid value will show an error message.
int inputInt(void);

// Read a positive integer value from user input. A zero or invalid value will show an error message.
int inputIntPositive(void);

// Read an integer value from user input within a specified range. An invalid value will show an error message and continue until the entered value is in range.
int inputIntRange(int lowerBound, int upperBound);

// Read a single character from user input and validate it against a list of valid characters. If character is not in the list of valid characters it will show an error message.
char inputCharOption(char str[]);

// Read a C string value from user input and validate that it contains a number of characters within the range of character specified by the 2nd and 3rd arguments received.
void inputCString(char* str, int minChar, int maxChar);

// Display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(char str[]);
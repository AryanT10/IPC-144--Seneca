/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <unistd.h>
#include <ctype.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
// Function to sort the values using bubble sort
void sort(struct Appointment appoints[], int max) {
    int i, j;
    struct Appointment temp;

    // Storing all the date and time values in minutes for comparison
    for (i = 0; i < max; i++) {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    // Using bubble sort to compare minutes and then swap the structs
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Converting total minutes back to minutes
    for (i = 0; i < max; i++) {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }

}

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int maximum, int fmt) {
    int i, eligible_record = 0;

    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }
    
    for (i = 0; i < maximum; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            eligible_record = 1;
        }
    }

    if (!eligible_record) {
        printf("*** No records found ***\n\n");
    }

    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int maximum) {
    int selection;

    // Print search menu and process user selection
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");

        switch (selection) {
            case 1:
                searchPatientByPatientNumber(patient, maximum);
                clearInputBuffer();
                suspend();
                break;
            case 2:
                searchPatientByPhoneNumber(patient, maximum);
                clearInputBuffer();
                suspend();
                break;
            case 0:
                // Exit search menu
                break;
            default:
                printf("*** Invalid selection! Please try again. ***\n\n");
                break;
        }
    } while (selection != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int maximum) {
    int i = 0, numRecords = 0, flag = 0;

    // Count existing patient records
    for (i = 0; i < maximum; i++) {
        if (patient[i].patientNumber == 0) {
            numRecords = i;
	    flag = 1;
        }
    }

    // Add new patient record if there is room in the list
    if (flag == 1) {
        patient[numRecords].patientNumber = nextPatientNumber(patient, maximum);
        inputPatient(&patient[numRecords]);
    }

   if(flag == 0){
	printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
	printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int maximum) {
    int patientNumber, index;

    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");

    // Find the index of the patient with the given patientNumber
    index = findPatientIndexByPatientNum(patientNumber, patient, maximum);

    if (index != -1) {
        // Call menuPatientEdit() to modify the patient record
        menuPatientEdit(&patient[index]);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
}


// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int pNumber, index;
    char choice, ch;
    printf("Enter the patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");

        int flag = 1;

        do {
            scanf(" %c%c", &choice, &ch);

            if ((choice == 'n' || choice == 'N') && (ch == '\n')) {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }
            else if ((choice == 'y' || choice == 'Y') && (ch == '\n')) {
                // Assigning patient to safe empty state so that the other function can't access it
                patient[index].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }
            else {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }    
        } while (flag);
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) 
{
    int i,j;

    // Sort the appointments by time
    sort(data->appointments, data->maxAppointments);

    // Display the header for the appointment table
    displayScheduleTableHeader(NULL, 1);

    // For each appointment, find and display the corresponding patient data
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    // Add a newline after the table
    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int lastDay = 31, i;
    struct Date date;

    // Get the year, month, and day from the user
    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    if (date.month == 4 || date.month == 9 ||  date.month == 11) {
        lastDay = 30;
    } else if (date.month == 2) {
        lastDay = 28 + (date.year % 4 == 0 ? 1 : 0);
    }

    printf("Day (1-%d)  : ", lastDay);
    date.day = inputIntRange(1, lastDay);
    printf("\n");

    // Sort the appointments by time
    sort(data->appointments, data->maxAppointments);

    // Display the appointment schedule for the chosen date
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        int patientIndex = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
        if (patientIndex == -1) {
            continue;
        }

        if (data->appointments[i].date.day == date.day && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day ) {
            displayScheduleData(&data->patients[patientIndex], &data->appointments[i], 0);
        }
    }

    // Add a newline after the table
    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *app, int maxAppointment, struct Patient *pt, int maxPatients) {

    struct Date date;
    struct Time time;

    // Declaring variables
    int lastDay = 31;
    int patientNumber, index, slotNotAvailable = 1;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);
    int timeSlotAvailable(struct Date date, struct Time time, struct Appointment *app, int maxAppointments);
    if (index >= 0)
    {
        while (slotNotAvailable)
        {
            // Taking the year as input
            printf("Year        : ");
            date.year = inputIntPositive();

            // Taking the month as input
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            // Taking the day as input
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 ||  date.month == 11) {
                lastDay = 30;
            }
            if (date.month == 2) {
                lastDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2) {
                lastDay = 29;
            }

            printf("%d)  : ", lastDay);
            date.day = inputIntRange(1, lastDay);
            
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking whether time slot is available
            if (timeSlotAvailable(date, time, app, maxAppointment)) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0)) {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0,23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0,59);
                }
                slotNotAvailable = 0;
            }
        }

        // Assigning the values to the next available slot

        index = nextSlotAvailable(app, maxAppointment);
        app[index].date = date;
        app[index].time = time;
        app[index].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }
}

// Remove an appointment record from the appointment arTodo:
void removeAppointment(struct Appointment *app, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int i = 0;
    printf("Patient Number: ");
    int number = inputIntPositive();
    int result = findPatientIndexByPatientNum(number, patients, maxPatient);
    if (result == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        struct Date date1;
        printf("Year        : ");
        date1.year = inputIntPositive();
        int febdays = date1.year % 4 == 0 ? 29 : 28;

        int months[12] = { 31, febdays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        printf("Month (1-12): ");

        date1.month = inputIntRange(1, 12);
        printf("Day (1-%d)  : ", months[date1.month - 1]);
        date1.day = inputIntRange(1, months[date1.month - 1]);

        int found = 0;
        int newindex = 0;
        for (i = 0; i < maxAppointments && !found; i++) {
            if (app[i].patientNumber == number) {
                found = 1;
                newindex = i;
            }

        }
        putchar('\n');
        displayPatientData(&patients[result], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        char option = inputCharOption("yn");

        if (option == 'y') {
            app[newindex].patientNumber = 0;
            app[newindex].date.year = 0;
            app[newindex].date.month = 0;
            app[newindex].date.day = 0;
            printf("\nAppointment record has been removed!\n");
        }
        else {
            printf("\n Operation Aborted!\n");
        }

        putchar('\n');
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int maximum) {
    int pNumber, index;
    printf("Search by patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, maximum) != -1) {
        index = findPatientIndexByPatientNum(pNumber, patient, maximum);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
    }

    else {
        printf("*** No records found ***\n\n");
    }
}


// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int maximum) {
    int match = 0;
    char phoneNumber[PHONE_LEN + 1];

    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("\n");

    // Display table header
    displayPatientTableHeader();
    int i;
    for (i = 0; i < maximum; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
            // Display patient information
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
        }
    }
    printf("\n");

    if (match == 0) {
        printf("*** No records found ***\n\n");
    }
}

int isEqual(const struct Date* d1, const struct Date* d2)
{
    return d1->year == d2->year && d1->month == d2->month && d1->day == d2->day;
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int maximum) {
    int maximumNum = 0; // Start with the minimum possible patient number
    int i;

    // Find the maximum patient number in the array
    for (i = 0; i < maximum; i++) {
        if (patient[i].patientNumber > maximumNum) {
            maximumNum = patient[i].patientNumber;
        }
    }

    // Return the next available patient number
    return maximumNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int maximum) {
    int i;
    for (i = 0; i < maximum; i++)
    {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    return -1;
}
// Checks to see whether a time slot is available
int timeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments) {
    int i, slotAvailable = 0;

    for (i = 0; i < maxAppointments; i++) {
        // Checking if time slot is available
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min) {
            slotAvailable = 1;
        }
    }

    return slotAvailable;
}

// Checks to see which is the next slot that is available and return the index
int nextSlotAvailable(struct Appointment* app, int maxAppointments) {
    int i = 0, available = 0;
    while (available == 0 && i < maxAppointments) {
        if (app[i].patientNumber < 1) {
            available = 1;
        }
        i++;
    }
    return i;
}

// Checks to see if an appointment is valid
int validAppointment(int patientNumber, struct Date date, struct Appointment *app, int maxAppointments) {
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year)) {
            valid = 1;
        }
        i++;
    }
    return i - 1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient *patient)
{
// Displaying form to take input
printf("Patient Data Input\n");
printf("------------------\n");
printf("Number: %05d\n", patient->patientNumber);
printf("Name  : ");
scanf("%[^\n]", patient->name);
    clearInputBuffer();
    if (strlen(patient->name))
    {
        printf("ERROR: String length must be no more than 15 chars: ");
        scanf("%[^\n]", patient->name);
        printf("\n");

    }
// Call the inputPhoneData function to take phone data input
inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) 
{
    int option;
   // Displaying phone input form
printf("Phone Information\n");
printf("-----------------\n");
printf("How will the patient like to be contacted?\n");
printf("1. Cell\n");
printf("2. Home\n");
printf("3. Work\n");
printf("4. TBD\n");
printf("Selection: ");
scanf("%d", &option);
printf("\n");

switch (option) {
    case 1:
        // Storing the description in the struct
        strncpy(phone->description, "CELL", PHONE_DESC_LEN+1);
        phone->description[PHONE_DESC_LEN] = '\0';
        printf("Contact: %s\n", phone->description);
        // Asking the user for a number as input and storing it in struct
        printf("Number : ");  
        scanf("%s",phone->number);
            do
            {
                if (strlen(phone->number) != PHONE_LEN)
                {
                    printf("Invalid 10-digit number! Number: ");
                    scanf("%s",phone->number);
                }
            } while (strlen(phone->number) != PHONE_LEN);
	    clearInputBuffer();
            printf("\n");
        break;       
    case 2:
        // Storing the description in the struct
          printf("Contact: ");
            puts("HOME");
            printf("Number : ");
        // Asking the user for a number as input and storing it in struct
       scanf("%s",phone->number);
            do
            {
                if (strlen(phone->number) != PHONE_LEN)
                {
                    printf("Invalid 10-digit number! Number: ");
                    scanf("%s",phone->number);
                }
            } while (strlen(phone->number) != PHONE_LEN);

            strncpy(phone->description, "HOME",PHONE_DESC_LEN);
            printf("\n");
            clearInputBuffer();
            break;
    case 3:
        // Storing the description in the struct
          printf("Contact: ");
            puts("WORK");
            printf("Number : ");
        // Asking the user for a number as input and storing it in struct
            scanf("%s",phone->number);
            do
            {
                if (strlen(phone->number) != PHONE_LEN)
                {
                    printf("Invalid 10-digit number! Number: ");
                    scanf("%s",phone->number);
                }
            } while (strlen(phone->number) != PHONE_LEN);

            strncpy(phone->description, "WORK", PHONE_DESC_LEN);
            printf("\n");
            clearInputBuffer();
            break;

    case 4:
        // Storing the description in the struct
         strncpy(phone->description, "TBD", PHONE_DESC_LEN);
            printf("\n");
            clearInputBuffer();
            break;
    default:
        printf("Error:\n");
        break;
}
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    // Declaring variables
    int i = 0;
    
    // Opening the file
    FILE *fp;
    fp = fopen(datafile, "r");

    // Checking for null pointer
    if (fp != NULL) {
        while (!feof(fp) && i < max) {
            fscanf(fp, "%d|%29[^|]|%4[^|]|", &patients[i].patientNumber , patients[i].name, patients[i].phone.description);

            if (!(strcmp(patients[i].phone.description, "TBD") == 0)) {
                fscanf(fp, "%[^\n]%*c", patients[i].phone.number);
            }
            i++;
        }
        fclose(fp);
    }

    else {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    // Declaring variables
    int i, count = 0;
    
    // Opening the file
    FILE *fp;
    fp = fopen(datafile, "r");

    // Checking for null pointer
    if (fp != NULL) {

        // Iterating until file reaches the end of file or the max is reached
        for (i = 0; i < max && !feof(fp); i++) {
            // Reading values from file and storing them
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            
            // Incrementing count if the end of file is not reached
            if (!feof(fp)) {
                count++;
            }
        }

        // Closing the file
        fclose(fp);
    }

    else {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return count;
}


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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>

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
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int maximum)
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
            displayAllPatients(patient, maximum, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, maximum);
            break;
        case 3:
            addPatient(patient, maximum);
            suspend();
            break;
        case 4:
            editPatient(patient, maximum);
            break;
        case 5:
            removePatient(patient, maximum);
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


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int maximum) {
    int i, numRecords = 0;

    // Count existing patient records
    for (i = 0; i < maximum; i++) {
        if (patient[i].patientNumber != 0) {
            numRecords++;
        }
    }

    // Add new patient record if there is room in the list
    if (numRecords < maximum) {
        int newRecordIndex = numRecords;
        patient[newRecordIndex].patientNumber = nextPatientNumber(patient, maximum);
        inputPatient(&patient[newRecordIndex]);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int maximum) {
    int patientNumber, index;
    char choice;

    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");

    // Find the index of the patient with the given patientNumber
    index = findPatientIndexByPatientNum(patientNumber, patient, maximum);

    if (index != -1) {
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else {
            // Remove the patient record by setting its patientNumber to 0
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
    for (i = 0; i < maximum; i++) {
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


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
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
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int maximum) {
    int i;
    for (i = 0; i < maximum; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    int i;
    char name[NAME_LEN];

// Displaying form to take input
printf("Patient Data Input\n");
printf("------------------\n");
printf("Number: %05d\n", patient->patientNumber);
printf("Name  : ");
fgets(name, sizeof(name), stdin);

// Storing the name in the struct
for (i = 0; i < strlen(name) - 1; i++) {
    patient->name[i] = name[i];
}

printf("\n");
// Call the inputPhoneData function to take phone data input
inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    int option, i;
    char inputNumber[PHONE_LEN + 1];
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
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        // Storing the number in the struct
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");
        break;

    case 2:
        // Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        // Storing the number in the struct
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");
        break;

    case 3:
        // Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        // Storing the number in the struct
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");
        break;

    case 4:
        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = 0; // Clearing the phone number

        break;

    default:
        printf("Error:\n");
        break;
}
}

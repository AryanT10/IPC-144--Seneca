/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : ARYAN TUWAR
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAXPRODUCT 3
#define SERVING 64
#define LBS_TO_KG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
    {
        int skuNumber;
        double productPrice;
        int calories;
        double productWeight;
    };
struct ReportData
    {
    int skuNum;
    double productPrice2;
    int productCalories;
    double productWeightLb;
    double productWeightKg;
    int productWeightGrams;
    double totalServing;
    double costPerServe;
    double caloriePerServe;
    };
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *resultint);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
    double getDoublePositive(double *resultdouble);


// 3. Opening Message (include the number of products that need entering)
    const int OpeningMessage(const int);


// 4. Get user input for the details of cat food product
    struct CatFoodInfo getCatFoodInfo(const int);


// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
    void displayCatFoodData(  int , double* ,  int ,  double*);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
    double convertLbsKg (double*, double*);

// 9. convert lbs: g
    int convertLbsG( double*, int*);

// 10. convert lbs: kg / g
    void convertLbs(double*, double*, int*);

// 11. calculate: servings based on gPerServ
    double calculateServings(const int, const int, double*);

// 12. calculate: cost per serving
    double calculateCostPerServing(const double, const double, double*);

// 13. calculate: cost per calorie
    double calculateCostPerCal(const double, const double, double*);

// 14. Derive a reporting detail record based on the cat food product data

    struct ReportData calculateReportData(struct CatFoodInfo foods);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
    void displayReportData(struct ReportData foods, const int);

// 17. Display the findings (cheapest)
    void displayFinalAnalysis(int, double);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();

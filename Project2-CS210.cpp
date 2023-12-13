// Jacob Rethmeier
// 11/26/2023
// CS-210: Project Two

//Main.cpp
#include <iostream>
#include <limits>
#include "InvestmentAccount.h"

using namespace std;

// Function to get valid input for a non-negative double
double getNonNegativeDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a non-negative number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break; // Break out of the loop if the input is valid
        }
    }
    return value;
}

// Function to get valid input for a non-negative integer
int getNonNegativeIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a non-negative number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break; // Break out of the loop if the input is valid
        }
    }
    return value;
}

int main() {
    double initialAmount, annualInterestRate, monthlyDeposit;
    int numberOfMonths, numberOfYears;

    // Get user input and validate
    initialAmount = getNonNegativeDoubleInput("Enter initial amount (non-negative): ");
    annualInterestRate = getNonNegativeDoubleInput("Enter annual interest rate (non-negative): ");
    monthlyDeposit = getNonNegativeDoubleInput("Enter monthly deposit (non-negative): ");
    numberOfMonths = getNonNegativeIntInput("Enter number of months (non-negative): ");
    numberOfYears = getNonNegativeIntInput("Enter number of years (non-negative): ");

    // Display entered values
    cout << "Initial Amount: $" << initialAmount << endl;
    cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Number of Months: " << numberOfMonths << endl;
    cout << "Number of Years: " << numberOfYears << endl;

    // Prompt user to continue
    cout << "Press any key to continue...";
    cin.ignore(); 
    cin.get();    

    // Create InvestmentAccount instance
    InvestmentAccount accountWithDeposit(initialAmount, annualInterestRate, monthlyDeposit);

    // Display monthly updates
    cout << "Monthly Updates for Account with Monthly Deposits:\n";
    accountWithDeposit.displayMonthlyUpdates(numberOfMonths);

    // Display yearly summary
    accountWithDeposit.displayYearlySummary(numberOfYears);

    return 0;
}
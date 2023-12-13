// InvestmentAccount.cpp
#include "InvestmentAccount.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0.0) {}

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit) {}

void InvestmentAccount::displayMonthlyUpdates(int numberOfMonths) {
    // Display header
    cout << setw(4) << "Month" << setw(14) << "Opening Amt" << setw(14) << "Deposited Amt"
        << setw(14) << "Total Amt" << setw(14) << "Interest Earned" << setw(14) << "Closing Balance" << endl;

    // Calculate and display values for each month
    double closingBalance = initialAmount;
    for (int month = 1; month <= numberOfMonths; ++month) {
        double monthlyInterest = closingBalance * (annualInterestRate / 100) / 12;
        closingBalance += monthlyDeposit + monthlyInterest;

        cout << setw(4) << month << fixed << setprecision(2)
            << setw(14) << closingBalance - monthlyDeposit << setw(14) << monthlyDeposit
            << setw(14) << closingBalance << setw(14) << monthlyInterest
            << setw(14) << closingBalance + monthlyInterest << endl;
    }
}

double InvestmentAccount::getEndingBalance(int numberOfYears) {
    double closingBalance = initialAmount;

    for (int year = 1; year <= numberOfYears; ++year) {
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = (closingBalance + monthlyDeposit) * (annualInterestRate / 100) / 12;
            closingBalance += monthlyDeposit + monthlyInterest;
        }
    }

    return closingBalance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears) {
    double totalInterest = 0.0;
    double closingBalance = initialAmount;

    for (int month = 1; month <= numberOfYears * 12; ++month) {
        double monthlyInterest = closingBalance * (annualInterestRate / 100) / 12;
        totalInterest += monthlyInterest;
        closingBalance += monthlyDeposit + monthlyInterest;
    }

    return totalInterest;
}

void InvestmentAccount::displayYearlySummary(int numberOfYears) {
    // Display yearly summary
    cout << "\nYearly Summary:\n";
    for (int year = 1; year <= numberOfYears; ++year) {
        double endingBalance = getEndingBalance(year);
        double interestEarned = getInterestEarned(year);

        cout << "Year " << year << ": Ending Balance - " << format(endingBalance)
            << ", Interest Earned - " << format(interestEarned) << endl;
    }
}

string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) {
    double endingBalance = getEndingBalance(numberOfYears);
    return format(endingBalance);
}

string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) {
    double interestEarned = getInterestEarned(numberOfYears);
    return format(interestEarned);
}

double InvestmentAccount::getInitialAmount() {
    return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit() {
    return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate() {
    return annualInterestRate;
}

double InvestmentAccount::round(double value, int places) {
    return value;
}

string InvestmentAccount::format(double value) {
    // Format as dollars
    double roundedValue = round(value, 2);  // Round to 2 decimal places
    stringstream stream;
    stream << fixed << setprecision(2) << roundedValue;
    return "$" + stream.str();
}
// InvestmentAccount.h
#pragma once

#include <string>

using namespace std;

class InvestmentAccount
{
public:
    InvestmentAccount(double initialAmount, double annualInterestRate); // mon. deposit is 0
    InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);

    void displayMonthlyUpdates(int numberOfMonths);
    void displayYearlySummary(int numberOfYears);

    double getEndingBalance(int numberOfYears); // calc ending balance after num years
    double getInterestEarned(int numberOfYears); // calc interest earned for num years

    string getEndingBalanceFormatted(int numberOfYears);  
    string getInterestEarnedFormatted(int numberOfYears); 

    double getInitialAmount();
    double getMonthlyDeposit();
    double getAnnualInterestRate();

    double round(double value, int places);
    string format(double value);

private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;
};
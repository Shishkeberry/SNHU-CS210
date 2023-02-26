/* CS 210 Project 2
   Airgead Banking App
   Written by Mary Sanders
   February 2, 2023
   */

#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>
#include "MenuScreen.h"
#include "UserValues.h"
using namespace std;

int main() {
    UserValues customerBanking;
    MenuScreen displayExample;

    double initalInvestmentAmount = 0.0;
    double monthlyDepositAmount = 0.0;
    double annualInterestRate = 0.0;
    int totalYears = 0;

    displayExample.MenuScreenView();
    system("PAUSE");

    customerBanking.GetUserInput(initalInvestmentAmount, monthlyDepositAmount, annualInterestRate, totalYears);
    customerBanking.WithoutDeposits(customerBanking.GetinitialInvestmentAmount(), customerBanking.GetAPR(), customerBanking.GetYears());
    customerBanking.WithDeposits(customerBanking.GetinitialInvestmentAmount(), customerBanking.GetMonthlyDeposit(), customerBanking.GetAPR(), customerBanking.GetYears());

    return 0;
}
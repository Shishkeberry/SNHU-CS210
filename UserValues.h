#pragma once
#ifndef USER_VALUES_H
#define USER_VALUES_H

#include <iostream>
#include <iomanip>
#include <string>
#include "MenuScreen.h"
using namespace std;


// Class declaration
class UserValues {

public:
	UserValues();
	void SetinitialInvestmentAmount(double t_initInvestment);
	void SetMonthlyDeposit(double t_monthlyContribution);
	void SetAPR(double t_percentageRate);
	void SetYears(int t_numYears);
	double GetinitialInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAPR() const;
	int GetYears() const;
	void GetUserInput(double t_initialInvestment, double t_monthlyDeposit, double t_APR, int t_numberOfYears);
	void WithoutDeposits(double t_initialInvestment, double t_APR, int t_numberOfYears);
	void WithDeposits(double t_initialInvestment, double t_monthlyDeposit,	double t_APR, int t_numberOfYears);
private:
	double m_initialInvestmentAmount = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_APR = 0.0;
	int m_totalYears = 0;
};

#endif 
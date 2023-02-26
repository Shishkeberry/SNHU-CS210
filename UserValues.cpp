#include "UserValues.h"

using namespace std;

// Class definition

UserValues::UserValues() {}

// mutators:

void UserValues::SetinitialInvestmentAmount(double t_initInvestment) {
    m_initialInvestmentAmount = t_initInvestment;
}

void UserValues::SetMonthlyDeposit(double t_monthlyContribution) {
    m_monthlyDeposit = t_monthlyContribution;
}
void UserValues::SetAPR(double t_percentageRate) {
    m_APR = t_percentageRate;
}

void UserValues::SetYears(int t_numYears) {
    m_totalYears = t_numYears;
}

// accessors
double UserValues::GetinitialInvestmentAmount() const {
    return m_initialInvestmentAmount;
}


double UserValues::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double UserValues::GetAPR() const {
    return m_APR;
}
int UserValues::GetYears() const {
    return m_totalYears;
}

void UserValues::GetUserInput(double t_initialInvestment, double t_monthlyDeposit, double t_APR, int t_numberOfYears) {
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $";


    while (!(cin >> t_initialInvestment) || t_initialInvestment < 0.00) {
        cout << "Invalid input. Please enter a valid deposit amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    UserValues::SetinitialInvestmentAmount(t_initialInvestment);

    cout << "Monthly Deposit: $";

    while (!(cin >> t_monthlyDeposit) || t_monthlyDeposit < 0.00) {
        cout << "Invalid input. Please enter a valid deposit amount";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    UserValues::SetMonthlyDeposit(t_monthlyDeposit);

    cout << "Annual Interest: %";

    while (!(cin >> t_APR)) {
        cout << "Invalid input. Please enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    UserValues::SetAPR(t_APR);

    cout << "Number of Years: ";

    while (!(cin >> t_numberOfYears) || t_numberOfYears < 1) {
        cout << "Invalid input. Please enter positive numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    UserValues::SetYears(t_numberOfYears);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << endl << endl;
}
// function to calculate totals with monthly deposits

void UserValues::WithDeposits(double t_initialInvestment, double t_monthlyDeposit,
    double t_APR, int t_numberOfYears) {
    double totalAmount = t_initialInvestment;


    cout << "        Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==========================================================================";
    cout << "=" << endl;
    cout << "   Year" << " " << setw(25) << "Year End Balance" << " " << setw(35);
    cout << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------------------";
    cout << "-" << endl;

   
    for (int i = 0; i < t_numberOfYears; ++i) {
        double yearlyEarnings = 0;
        double monthlyEarnings;

        for (int j = 0; j < 12; ++j) {

         monthlyEarnings = (totalAmount + t_monthlyDeposit) * ((t_APR / 100) / 12);
         yearlyEarnings = yearlyEarnings + monthlyEarnings;
         totalAmount = totalAmount + t_monthlyDeposit + monthlyEarnings;
        }
     
        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalAmount).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalAmount).size()) << totalAmount << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;

    }
    cout << endl;
}

// fucntion to calculate totals without monthly deposits

void UserValues::WithoutDeposits(double t_initialInvestment,
    double t_APR, int t_numberOfYears) {
    double totalAmount = t_initialInvestment;

    cout << "        Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================================";
    cout << "=" << endl;
    cout << "   Year" << " " << setw(25) << "Year End Balance" << " " << setw(35);
    cout << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------------------";
    cout << "-" << endl;

    for (int i = 0; i < t_numberOfYears; ++i) {
        double yearlyEarnings = 0;
        double monthlyEarnings;

        for (int j = 0; j < 12; ++j) {
            monthlyEarnings = (totalAmount) * ((t_APR / 100) / 12);
            yearlyEarnings = yearlyEarnings + monthlyEarnings;
            totalAmount = totalAmount + monthlyEarnings;
        }

        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalAmount).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalAmount).size()) << totalAmount << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;
    }
    cout << endl << endl;
}
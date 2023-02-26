#include <iostream>
#include <string>
#include "MenuScreen.h"

using namespace std;
//class constructor
MenuScreen::MenuScreen() {}

void MenuScreen::MenuScreenView() {
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of Years: " << endl;
    cout << endl;
}
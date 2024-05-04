#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(double ba, double ir)
	: Account(ba), interestRate(ir)
{
    if (interestRate < 0.0)
    {
        cout << "Invalid interest rate. Setting to 0.0." << endl;
        interestRate = 0.0;
    }
}

double SavingsAccount::calculateInterest()
{
    return getBalance() * interestRate;
}
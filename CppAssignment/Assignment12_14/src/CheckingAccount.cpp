#include "CheckingAccount.h"
#include <iostream>
using namespace std;
CheckingAccount::CheckingAccount(double balance, double fee)
	: Account(balance), fee(fee)
{
    if (fee < 0.0)
    {
        cout << "Error: Fee cannot be negative. Setting to 0.0." << endl;
        fee = 0.0;
    }
}

void CheckingAccount::credit(double amount)
{
    double temp = amount - fee;
    Account::credit(temp);
}

bool CheckingAccount::debit(double amount)
{
    double temp = amount + fee;
    return Account::debit(temp);
}
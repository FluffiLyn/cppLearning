#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(double balance)
{
    if (balance < 0.0)
    {
        cout << "Error: balance cannot be negative." << endl;
        exit(1);
    }
	this->balance = balance;
}

void Account::credit(double& amount)
{
	balance += amount;
}

bool Account::debit(double& amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		return true;
	}
	else
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	}
}
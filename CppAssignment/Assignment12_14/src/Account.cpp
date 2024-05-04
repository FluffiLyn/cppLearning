#include "Account.h"
#include <iostream>
using namespace std;

Account::Account()
{}

Account::Account(double balance): balance(balance)
{
    if (balance < 0.0)
    {
        cout << "Error: balance cannot be negative. Setting to 0.0." << endl;
		balance = 0.0;
	}
}

void Account::credit(double amount)
{
	balance += amount;
}

bool Account::debit(double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		return true;
	}
	else
	{
		cout << "Debit amount $" << amount << " exceeded account balance." << endl;
		return false;
	}
}

double Account::getBalance()
{
	return balance;
}
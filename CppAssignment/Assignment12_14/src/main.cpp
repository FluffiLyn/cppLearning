#include <iostream>
#include <vector>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
    vector<Account*> accounts(4);
    accounts.at(0) = new SavingsAccount(25.0, 0.0);
    accounts.at(1) = new CheckingAccount(80.0, 1.0);
    accounts.at(2) = new SavingsAccount(200.0, 0.015);
    accounts.at(3) = new CheckingAccount(400.0, 0.5);

    cout << fixed << setprecision(2);

    for (int i = 0; i < accounts.size(); ++i)
    {
        cout << "Account " << i + 1 << " balance: $"
              << accounts[i]->getBalance();

        double withdrawalAmount = 0.0;

        cout << "\nEnter an amount to withdraw from Account " << i + 1
                  << ": ";
        cin >> withdrawalAmount;

        accounts[i]->debit(withdrawalAmount);

        double depositAmount = 0.0;

        cout << "Enter an amount to deposit into Account " << i + 1
                  << ": ";
        cin >> depositAmount;
        accounts[i]->credit(depositAmount);

        SavingsAccount *savingsAccountPtr = dynamic_cast<SavingsAccount *>(accounts[i]);

        if (savingsAccountPtr != 0)
        {
            double interestEarned = savingsAccountPtr->calculateInterest();
            cout << "Adding $" << interestEarned << " interest to Account "
                      << i + 1 << " (a SavingsAccount)" << endl;
            savingsAccountPtr->credit(interestEarned);
        }

        cout << "Updated Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << "\n\n";
    }
    return 0;
}
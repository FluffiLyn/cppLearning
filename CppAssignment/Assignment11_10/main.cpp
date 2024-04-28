#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
    Account a1(1000.0), a2(-1.0);
    cout << "Balance of a1: " << a1.getBalance() << endl;
    a1.credit(2000.0);
    cout << "Balance of a1 after crediting $2000.0: " << a1.getBalance() << endl;
    
    if (a1.debit(1000.0))
        cout << "Balance of a1 after debiting $1000.0: " << a1.getBalance() << endl;

    if (a1.debit(2500.0))
        cout << "Balance of a1 after debiting $2500.0: " << a1.getBalance() << endl;

    SavingsAccount s1(1000.0, 0.05), s2(-1.0, 0.05);
    cout << "Balance of s1: " << s1.getBalance() << endl;
    cout << "Interest rate of s1: " << s1.calculateInterest() << endl;
    
    s1.credit(2000.0);
    cout << "Balance of s1 after crediting $2000.0: " << s1.getBalance() << endl;

    if (s1.debit(1000.0))
        cout << "Balance of s1 after debiting $1000.0: " << s1.getBalance() << endl;

    CheckingAccount c1(1000.0, 10.0), c2(1.0, -100.0);
    cout << "Balance of c1: " << c1.getBalance() << endl;
    c1.credit(1000.0);
    cout << "Balance of c1 after crediting $1000.0: " << c1.getBalance() << endl;
    if (c1.debit(1000.0))
        cout << "Balance of c1 after debiting $1000.0: " << c1.getBalance() << endl;

    return 0;
}
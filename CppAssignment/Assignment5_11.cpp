#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double amount;
    double principal = 1000.0;
    double rate = 0.10;
    
    cout << fixed << setprecision(2);

    for(rate; rate <= 0.16; rate += 0.01) 
    {
        cout << setw(7) << "Year" << setw(36) << "Amount on deposit(rate = " << rate << ")" << endl;
        for (unsigned  int year = 1; year <=10; ++year)
        {
            amount = principal * pow(1.0 + rate, year);

            cout << setw(4) << year << setw(21) << amount << endl;
        }
        cout << "\n";
    }

    return 0;
}
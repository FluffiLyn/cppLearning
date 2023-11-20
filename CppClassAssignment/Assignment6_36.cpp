#include <iostream>
using namespace std;

int recPow(int base, int exp)
{
    if ( exp == 0 )
    {
        return 1;
    }
    else if ( exp > 0 )
    {
        return base * recPow(base, exp - 1);
    }
}

int main()
{
    int base, exp;
    cout << "Please enter the base and the exponent: " << endl;
    cin >> base >> exp;
    
    cout << recPow(base,exp) << endl;

    return 0;
}
#include <iostream>
using namespace std;

int integerPower(int base, int exp)
{
    int result = 1;
    for (int i = 1; i <= exp; i++)
    {
        result = result * base;
    }
    return result;
}

int main()
{
    int x = 3, y = 4;
    cout << integerPower(x, y) << endl;
    
    return 0;
}
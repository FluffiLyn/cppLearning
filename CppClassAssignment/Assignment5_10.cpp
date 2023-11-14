#include <iostream>
using namespace std;

long long int factorial(int a)
{
    int f = 1;
    for(int i = 1; i <=a; i++)
    {
        f *= i;
    }
    return static_cast<long long int>(f);
}

int main()
{
    for(int n = 1; n <= 7; n++)
    {
        cout << n << "! = " << factorial(n) << endl;
    }
    return 0;
}
//Difficulty: overflow.

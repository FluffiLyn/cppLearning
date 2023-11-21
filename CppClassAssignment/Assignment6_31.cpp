#include <iostream>
using namespace std;

int lcm(int x, int y)
{
    for (int i = 1;;i++)
    {
        if ((i % x == 0) && (i % y == 0))
        {
            return i;
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);

    return 0;
}
//Actually this is brute force. A better way to find the LCM is to find GCD first, then LCM = (a * b) / GCD.
//Here is a function that uses Euclidean algorithm（辗转相除法）to find GCD.

/*
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
*/
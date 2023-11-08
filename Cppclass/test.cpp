#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, char x, char y, char z)
{
    if(n == 1)
        cout << x << "-->" << z << endl;
    else
    {
        hanoi(n - 1, x, z, y);
        cout << x << "-->" << z << endl;
        hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int m;
    cout << "Input the number of diskes:" << endl;
    cin >> m;
    hanoi(m,'A','B','C');
    cout << "steps = 2^n - 1 = " << pow(2,m) - 1;
    
    return 0;
}
#include <iostream>
using namespace std;

template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    int x = 1, y = 2;
    long a = 3, b = 4; 
    float c = 5.5, d = 6.6;
    cout << "x + y = " <<sum(x, y) << ", a + b = " << sum(a, b) << ", c + d = "<< sum(c, d);
    return 0;
}
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
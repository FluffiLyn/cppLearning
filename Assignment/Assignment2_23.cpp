#include <iostream>
using namespace std;
int main()
{
    int a, b, c, max, min;
    
    cout << "Please enter 3 numbers: \n";
    cin >> a >> b >> c;
    if (a > b)
        max = a, min = b;
    else
        max = b, min = a;
    
    if (max < c)
        max = c;
    else if (min > c)
        min = c;
    
    cout << "max=" << max << endl << "min=" << min;
    return 0;
}
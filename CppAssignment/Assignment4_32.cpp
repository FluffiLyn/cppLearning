#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a,b,c;
    
    cout << "Please enter 3 numbers:" << endl;
    cin >> a >> b >> c;

    if(a + b > c && b + c > a && a + c > b)
        cout << "They can represent a triangle." << endl;
    else
        cout << "They cannot represent a triangle." << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int a,b,c,sum;
    
    cout << "Please enter the first number:" ;
    cin >> a;

    cout << "\nPlease enter the second number:";
    cin >> b;

    cout << "\nPlease enter the third number:";
    cin >> c;

    sum = a + b + c;
    cout << "The sum is:" << sum ;
    return 0;
}
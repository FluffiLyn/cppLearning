#include <iostream>
using namespace std;

int main()
{
    int a,b;

    cout << "Please enter 2 numbers:" << endl;
    cin >> a >> b;

    if (b % a == 0)
        cout << a << " is a factor of " << b << endl;
    else
        cout << a << " is not a factor of " << b << endl; 
    
    system("pause");
    return 0;
}
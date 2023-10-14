#include <iostream>
using namespace std;

int main()
{
    int a;
    
    cout << "Please enter an integer:";
    cin >> a;

    if (a % 3 == 0)
        cout << "\nThis number is divisible by 3.";
    else
        cout << "This number is not divisible by 3.";
    
    system("pause");
    return 0;
}
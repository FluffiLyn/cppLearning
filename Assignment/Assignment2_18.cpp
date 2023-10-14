#include <iostream>
using namespace std;

int main()
{
    int num1,num2;
    
    cout << "This is a program about comparing integers" << endl;
    
    cout << "Please enter the first number (int):";
    cin >> num1;

    cout << "\nPlease enter the second number (int):";
    cin >> num2;

    if (num1 > num2)
        cout << num2 << " is smaller" << endl;
    else if (num1 == num2)
        cout << "They are equal" << endl;
    else
        cout << num1 << " is smaller" << endl;
    
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    while(1)
    {
        float a = 0;
        cout << "Enter sales in dollars (-1 to end): ";
        cin >> a; 

        if (a != -1)
            cout << "Salary is: $" << 200 + a * 0.09 <<endl;
        else
            break;
    }

    return 0;
}
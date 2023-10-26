#include <iostream>
using namespace std;

int main()
{
    while(1)
    {
        int hour;
        float rate;
        
        cout << "Enter hours worked (-1 to end):"; 
        cin >> hour;
        
        if(hour != -1)
        {
            cout << "\nEnter hourly rate of the employee ($00.00):";
            cin >> rate;

            if(hour <= 40)
            {
                cout << "\nSalary is:" << hour * rate << endl;
            }
            else
                cout << "\nSalary is:" << rate * 40 + 1.5 * rate * (hour - 40) << endl;
        }
        else
            break;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() 
{
    int numValues;
    cout << "Enter the number of values: ";
    cin >> numValues;
    
    int maxValue;
    cout << "Enter value 1: ";
    cin >> maxValue;

    for (int i = 2; i <= numValues; ++i) 
    {
        int currentValue;
        cout << "Enter value " << i << ": ";
        cin >> currentValue;
        if (currentValue > maxValue) 
        {
            maxValue = currentValue;
        }
    }

    cout << "The largest value is: " << maxValue << endl;
    return 0;
}

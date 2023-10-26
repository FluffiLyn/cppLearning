#include <iostream>
using namespace std;

int main()
{
    int counter = 0, number = 0, largest = 0;

     while(counter <= 9)
     {
        cout << "Enter a number(" << counter + 1 << "): ";
        cin >> number;

        if(largest == number)
        {
            counter++;
            continue;
        }
        else if(largest > number)
        {
            counter++;
            continue;
        }
        else
            counter++;
            largest = number;
            continue;
     }
     
     cout << "The largest number is:" << largest;

     return 0; 
}

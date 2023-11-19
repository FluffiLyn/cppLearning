#include <iostream>
#include <iomanip>
using namespace std;

double calculateCharges(double hours)
{
    if (hours <= 3)
    {
        return 2.00;
    }
    else if (hours <=19)
    {
        return 2.00 + 0.50 * (hours - 3.00);
    }
    else 
    {
        return 10.00;
    }
}
int main()
{
    double hours, totalHours, totalCharge;
    int N;
    
    cout << "Please enter number of customers: ";
    cin >> N;
    double* arr = new double[N];
    
    cout << "Please enter hours parked for each customer: ";
    for (int i = 0; i < N; i++)
    {
        cin >> hours;
        arr[i] = hours;    
    }

    cout << "Car\tHours\tCharge" << endl; 
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "\t" << fixed << setprecision(1) << arr[i] << "\t" 
        << fixed << setprecision(2) << calculateCharges(arr[i]) << endl;
        
        totalHours = totalHours + arr[i];
        totalCharge = totalCharge + calculateCharges(arr[i]);
    }
    cout << "Total\t" << fixed << setprecision(2) <<  totalHours << "\t" << fixed << setprecision(4) << totalCharge;
    return 0;
}
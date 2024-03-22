#include <iostream>
using namespace std;

double Pi(int n) //n is iteration of function Pi.
{
    double pi = 0.0;
    bool subtract = false;//Use "bool" to determine whether it's - or +
    double divisor = 1.0;

    for (int i = 0; i < n; i++) 
    {
        if (subtract) 
        {
            pi -= 4.0 / divisor;
        } 
        else 
        {
            pi += 4.0 / divisor;
        }
        
        subtract = !subtract;//Reverse the sign
        divisor += 2.0;
    }

    return pi;
}

int main() 
{
    int n;
    cout << "Enter the number of iterations: ";
    cin >> n;

    cout << "Approximate value of pi after " << n << " iterations: " << Pi(n) << endl;

    return 0;
}

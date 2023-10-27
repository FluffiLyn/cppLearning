#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double factf(int n)//Calculate the factorial of n.
{
    if(n==1 || n == 0)
        return 1;
    else
        return n * factf(n - 1);
}

long double value_of_e(double x, int prec)//Calculate the approximation of e with given precision.
{
    long double e = 1.0;
    long double term = 1;
    int n = 1;

    setprecision(prec);
    
    while (term > pow(10, -prec)) 
    {
        term = pow(x,n) / factf(n);
        e += term;
        n++;
    }

    return e;
}

int main()
{
    int m,precision;
    double x;
   
    //Compute m!
    cout << "Please enter an integer m:";
    cin >> m;
    cout << "m! = " << static_cast<long int>(factf(m)) << endl;

    //Compute e
    cout << "Please enter the precision of e (number of digits):";
    cin >> precision;
    cout << "e=" << setprecision(precision) << value_of_e(1, precision) << endl;

    //compute e^x
    cout << "Please enter the number of x and the precision:";
    cout << "e^" << x << "=" << setprecision(precision) << value_of_e(x, precision) << endl;
    return 0;

}
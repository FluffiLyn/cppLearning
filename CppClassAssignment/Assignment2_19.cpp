#include <iostream>
using namespace std;

double max(double a, double b, double c)
{
    if (a > b)
    {   if (a > c)
            return a;
         else 
            return c;
    }
    else 
    {   if (c > b)
            return c;
        else
            return b;
    }
}

double min(double a, double b,double c)
{
    if (a < b)
    {   if (a < c)
            return a;
         else 
            return c;
    }
    else 
    {   if (c < b)
            return c;
        else
            return b;
    }
}

int main()
{
    double a,b,c,sum,average,product;
    
    start:
    cout << "Input three different integers: "<< endl;
    cin >> a >> b >> c;

    if (a==b && a==c )
    {
        cout << " Please input three different integers!!!!" << endl;
        goto start;
    }
    
    sum = a + b + c;
    average = sum / 3;
    product = a * b * c;
  
    cout << "Sum is " << sum << endl;
    cout << "Average is " << average << endl;
    cout << "Product is " << product << endl;
    cout << "Smallest is " << min(a,b,c) << endl;
    cout << "Largest is " << max(a,b,c) << endl;
    
    system("pause");
    return 0;
}
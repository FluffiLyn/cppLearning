#include "Complex.h"
using namespace std;

int main()
{
    Complex x, y(4.3, 8.2), z(3.3, 1.1);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    x = y + z;
    cout << "x = y + z = " << x << endl;

    x = y - z;
    cout << "x = y - z = " << x << endl;

    x = y * z;
    cout << "x = y * z = " << x << endl;

    Complex a(1.1, 1.1), b(1.1, 1.2);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    if (a == b) 
    {
        cout << "a == b" << endl;
    }
    else 
    {
        cout << "a != b" << endl;
    }
}

#include "Complex.cpp"
#include <iostream>

using namespace std;

int main()
{
    int x{4};
    int y{8};
    int a{10};
    int b{5};
    int g{2};
    int i{4};
    int j{9};

    cout << "Current variable values are:" << endl
         << "x = " << x << ", y = " << y << ", a = " << a
         << ", b = " << b << ", g = " << g << ", i = " << i
         << ", j = " << j << endl << endl;

    if ((!(x < 5) && !(y >= 7)) == (!((x < 5) || (y >= 7))))
    {
        cout << "!(x < 5) && !(y >= 7) is equivalent to"
             << " !((x < 5) || (y >= 7))" << endl << endl;
    }

    if ((!(a == b) || !(g != 5)) == (!((a == b) && (g != 5))))
    {
        cout << "!(a == b) || !(g != 5) is equivalent to"
             << " !((a == b) && (g != 5))" << endl << endl;
    }

    if ((!((x <= 8) && (y > 4))) == (!(x <= 8) || !(y > 4)))
    {
        cout << "!((x <= 8) && (y > 4)) is equivalent to"
             << " !(x <= 8) || !(y > 4)" << endl << endl;
    }

    if ((!((i > 4) || (j <= 6))) == (!(i > 4) && !(j <= 6)))
    {
        cout << "!((i > 4) || (j <= 6)) is equivalent to"
             << " !(i > 4) && !(j <= 6)" << endl << endl;
    }

    return 0;
}
#include "RationalNumber.h"

int main()
{
    RationalNumber r1(1, 2), r2(3, 4), r3(2,-2);
    cout << r1 + r2 << endl;
    cout << r1 - r2 << endl;
    cout << r1 * r2 << endl;
    cout << r1 / r2 << endl;

    if (r1 > r3)
        cout << r1 <<">" << r3 << endl;

    if (r2 < r3)
        cout << r2 << "<" << r3 << endl;
    if (r1 == r2)
        cout << r1 << "==" << r2 << endl;
    if (r1 != r2)
        cout << r1 << "!=" << r2 << endl;
    if (r1 >= r2)
        cout << r1 << ">=" << r2 << endl;
}


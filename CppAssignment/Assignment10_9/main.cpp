#include <iostream>
#include  "HugeInt.h"
using namespace std;

int main()
{
    HugeInt n1(7654321), n2(7891234), n3("999999999999999"), n4("1"), n5;

    cout << "n1 is " << n1 << "\nn2 is " << n2 
        << "\nn3 is " << n3 << "\nn4 is " << n4 
        << "\nn5 is " << n5 << endl;

    n5 = n1 + n2;

    cout << n1 << "+" << n2 << "=" << n5 << endl;

    cout << n3 << "+" << n4 << "=" << n3 + n4 << endl;

    n5 = n1 + 9;
    cout << n1 << "+" << 9 << "=" << n5 << endl;

    n5 = n2 + "10000";
    cout << n2 << "+" << "10000" << "=" << n5 << endl;

    n5 = n1 * n2;
    cout << n1 << "*" << n2 << "=" << n5 << endl;

    n1 = 1111111, n2 = 2222222;
    n5 = n2 / n1;
    cout << n2 << "/" << n1 << "=" << n5 << endl;

    if (n1 > n4)  cout << n1 << ">" << n4 << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int i = 2;
    int product = 1;
    for(i ; i <= 15 ; i += 2)
    {
        product = product * i;
    }

    cout << "The product of even integers from 1 to 15 is: " << product << endl;

    return 0;
}
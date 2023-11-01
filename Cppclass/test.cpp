#include <iostream>
using std::cout;
using std::endl;

int number = 7;//Global variable named "number".

int main()
{
    double number = 10.5;//Local variable named number.

    cout << "Local double value of number = " << number
        << "\nGlobal int value of number = " << ::number << endl;

    return 0;
}
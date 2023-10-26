#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    long int binaryNum, decimalNum = 0;
    int base = 1;

    cout << "Please enter a binary number:" << endl;
    cin >> binaryNum;

    while (binaryNum > 0) 
    {
        int lastDigit = binaryNum % 10;//Get the rightmost digit
        decimalNum += lastDigit * base;//Sum 
        binaryNum /= 10;//Truncate the rightmost digit
        base *= 2;
    }

    cout << "The decimal number is:" << decimalNum;
    return 0;
}

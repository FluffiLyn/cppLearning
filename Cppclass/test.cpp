#include <iostream>
using namespace std;

int cubeByValue(int);//Prototype
void cubeByReference(int *);//Prototype

int main()
{
    int number = 5;

    cout << "The original value of number is: " << number << endl;

    number = cubeByValue(number);
    cout << "\n The New value of n is : " << number << endl;

    number = 5;

    cubeByReference(&number);
    cout << "\n The New value of n is : " << number << endl;
}

int cubeByValue(int n)
{
    return n * n * n;
}

void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;//No return but change "number"
}
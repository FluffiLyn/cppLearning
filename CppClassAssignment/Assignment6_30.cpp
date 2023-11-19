#include <iostream>
using namespace std;

int reverse(int num)
{
    int reversedNum = 0;
    while (num != 0)
    {
        int digit = num % 10; 
        reversedNum = reversedNum * 10 + digit; 
        num /= 10; 
    }
    return reversedNum;
}

int main()
{
    int num;
    cout << "Please enter an integer:";
    cin >> num;
    cout << "The result: " << reverse(num) << endl;

    return 0;
}

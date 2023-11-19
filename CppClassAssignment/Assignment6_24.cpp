#include <iostream>
using namespace std;

void Separation(int num) 
{
    if (num >= 0 && num <= 32767) 
    {
        int digits[5] = {0}; 
        int index = 0;
        while (num > 0) 
        {
            digits[index++] = num % 10;
            num /= 10; //Remove the rightmost digit
        }
        for (int i = index - 1; i >= 0; i--) 
        {
            cout << digits[i] << " ";
        }
        cout << endl;
    } 
    else 
    {
        cout << "Out of range (1~32767)" << endl;
    }
}

int main() {
    int input;
    cout << "Please enter an integer between 1~32767: ";
    cin >> input;
    Separation(input);
    return 0;
}

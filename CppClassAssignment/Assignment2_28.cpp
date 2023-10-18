#include <iostream>
using namespace std;

int main()
{
    int i;

    cout << "Please enter a 5-digit number:" << endl;
    cin >> i;

    cout << i / 10000 << "\t" << i / 1000 % 10 << "\t" 
         << i / 100 % 10 << "\t" << i / 10 % 10 << "\t"
         << i % 10 << endl;

    system("pause");
    return 0;
}
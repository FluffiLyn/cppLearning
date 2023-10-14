#include <iostream>
using namespace std;

int main()
{
    char a;

    cout << "Please enter any character in ASCII character set:";
    cin >> a;

    cout << static_cast< int >(a);

    system("pause");
    return 0;
}
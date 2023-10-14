#include <iostream>
using namespace std;

int main()
{
    const double pi = 3.14159;
    int radius,height;

    cout << "Please enter the radius: " << endl;
    cin >> radius;

    cout << "Please enter the height: " << endl;
    cin >> height;

    cout << "The volume is " << 2 * pi * radius * height << endl;
    cout << "The surface area is " << 2 * pi * radius * radius 
                                    + 2 * pi * radius * height << endl;
    system("pause");
    return 0;
}
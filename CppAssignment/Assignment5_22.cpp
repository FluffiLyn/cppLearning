#include <iostream>
using namespace std;

int main()
{
    int x = 1, y = 2;

    if ((!(x < 5) && !(y >= 7)) == !(x < 5 || y >= 7))
    {
        cout << "a) They are equivalent" << endl;
    }

    int a = 3, b = 4, g = 5;

    if ((!(a == b) || !(g != 5)) == !((a == b) && (g != 5)))
    {
        cout << "b) They are equivalent" << endl;
    }

    if (!((x <= 8) && (y > 4)) == (!(x <= 8) || !(y > 4)))
    {
        cout << "c) They are equivalent" << endl;
    }


    int i = 6, j = 7;
    if (!(i > 4 || j <= 6) == (!(i > 4) && !(j <= 6)))
    {
        cout << "d) They are equivalent" << endl;
    }
    
    return 0;
}





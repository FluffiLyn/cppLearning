#include <iostream>
#include <sys/types.h>
using namespace std;

bool multiple(int x, int y)
{
    if (x % y == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    
    
    for(;;)
    {
        cout << "Please enter a series of integers:(enter -1 twice to end) " << endl;
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1) 
            break;
        else if (multiple(x, y))
        {
            cout << "true" << endl;
        }
        else 
        {
            cout << "false" << endl;
        }
    }
 
    return 0;
}
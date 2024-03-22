#include <iostream>
using namespace std;

int seconds_(int hour, int min, int sec)
{
    return sec + min * 60 + hour * 3600;
}

int main()
{ 
    int x, y, z;
    cout << "Please enter the current time (hours, minutes, seconds) : ";
    cin >> x >> y >> z;

    cout << "The number of seconds since the last time the clock struck 12 is: " << seconds_(x, y, z) << endl;
    
    return 0;
}
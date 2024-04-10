#include <iostream>
using namespace std;

int main()
{
    int n = 0, sum = 0, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sum /= n;
    


    return 0;
}
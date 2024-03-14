#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d(6);

    for (int i = 0; i < 6; i++)
    {
        d.at(i) = 100 * (i + 1);
    }

    //通过[]访问
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    
    //通过at()访问
    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }

    return 0;
}
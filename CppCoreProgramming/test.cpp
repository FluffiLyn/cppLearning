#include <iostream>
#include <set>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

int main()
{
    set<int, MyCompare> s1;

    for (int i = 10; i <= 70; i += 10)
    {
        s1.insert(i);
    }

    for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }

    cout<< endl;

    return 0;
}
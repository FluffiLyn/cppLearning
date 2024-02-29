#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec(3,0);

    vec.insert(vec.begin()+2,1);
    for (int i: vec)
    {
        cout << vec.at(i);
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
for (int i = 0; i < 10; ++i)
{
    v1.push_back(i);
}
vector<int> v2(v1.begin(), v1.end());

}
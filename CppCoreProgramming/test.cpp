#include <iostream>
#include <map>
using namespace std;

int main() 
{
    map<int, int> m1;
    
    //1
    m1.insert(pair<int, int>(1,10));

    //2
    m1.insert(make_pair(2,20));

    //3
    m1.insert(map<int, int>::value_type(3,30));

    //4
    //不建议，如果该键已经存在，它会直接覆盖原有的值。这可能会导致意外的数据丢失，特别是在不确定键是否存在的情况下。
    m1[4] = 40;

    //当你用[]访问不存在的键时，它会新建一个键值对，实值的默认值是0，导致意外的元素插入。
    cout << m1[5];

    return 0;
}
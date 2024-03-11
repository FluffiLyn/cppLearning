#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    for(int i : v) cout << i << " ";
    cout << endl;

    //输出第二个数据
    cout << *(v.begin()+1) << endl;
    //在第二个元素处添加200
    v.insert(v.begin() + 1,200);
    cout << *(v.begin()+ 2) << endl;

    //在第一个元素处向后添加两个100
    v.insert(v.begin(),2,100);
    for (int i : v) cout << i << " ";
    cout << endl;

    //清空所有的100元素（删除当前元素后，迭代器会自动指向后一个元素，此时不能++，否则会出错）
    for(vector<int>::iterator it = v.begin(); it != v.end();)
    {
        if (*it == 100)
            it = v.erase(it);//erase函数返回的是下一个元素的迭代器
        else 
            it++;
    }
    
    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}
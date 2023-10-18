#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int * p;//定义一个指针

    p = &a;//让指针记录变量a的地址
    cout << "The address of a is:" << &a << endl;
    cout << "指针p为：" << p << endl;

    *p = 1000;//指针前面加一个*，代表解引用，找到指针指向的内存中的数据
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    
    return 0;
}
#include <iostream>
using namespace std;
//空指针：指针变量指向内存中编号为0的空间
//用途：初始化指针变量

//WARNING:空指针指向的内存是 不 可 访 问 的！
//0~255之间的内存编号是系统占用的，因此没有权限访问。(比如你不能cout << *p ;)

int main()
{
    int * p = nullptr;

    cout << *p << endl;
    return 0;
    
}
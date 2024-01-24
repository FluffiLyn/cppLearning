#include <iostream>
using namespace std;

class Person1{};//空类

void test01()
{
    Person1 p1;
    //空对象占用内存空间是 1
    //c++编译器会给每个空对象也分配一个字节空间，为了区分空对象站内存的位置。
    //每个空对象也有一个独一无二的内存地址
    cout << "Size of p is "<< sizeof(p1) << endl;
}

class Person2
{
    int m_A;//非静态成员变量 属于类对象上
    static int m_B;//静态成员变量 不属于类对象上
    void func(){}//非静态成员函数 不属于类对象上
};
int Person2::m_B = 114514;

void test02()
{
    Person2 p2;
    //此处输出4，包括m_A的长度，不包括m_B和func()的长度。
    cout << "Size of p2 is " << sizeof(p2) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}

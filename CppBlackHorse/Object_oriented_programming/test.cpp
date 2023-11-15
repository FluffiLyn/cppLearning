#include <iostream>
using namespace std;

class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }

    Person(int age)
    {
        cout << "Person有参构造函数调用" << endl;
        m_Age = age;
    }

    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
    }

    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);

    cout << "P2的年龄为：" << p2.m_Age << endl;
}

//2、值传递的方式给函数参数传值（相当于Person p = p拷贝构造函数的隐式写法）
void doWork(Person p)//doWork的p是doWork的局部变量，局部变量接受外部的对象时，
{                    //使用拷贝构造来把数据复制一份给自己

}                    

void test02()
{
    Person p;
    doWork(p);
}

//3、值方式返回局部对象
Person doWork2()
{
    Person p3;
    cout << (int*)&p3 << endl;
    return p3;
}

void test03()
{
    Person p4 = doWork2();
    cout << (int*)&p4 << endl;
}


int main()
{
    test01();
    test02();
    test03();
    return 0;
}



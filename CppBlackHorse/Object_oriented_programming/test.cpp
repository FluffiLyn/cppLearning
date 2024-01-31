#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    
    Person(int age)
    {
        m_Age = new int(age);
    }

    //不要在析构函数那里delete这个指针
    int *m_Age;

};


void test01()
{
    Person p1(18);
    cout << "p1的年龄为" << *p1.m_Age << endl;
    Person p2(20);
    
    p2 = p1;
    cout << "p1的年龄为" << *p2.m_Age << endl;
}

int main()
{
    test01();  
    
    return 0;
}

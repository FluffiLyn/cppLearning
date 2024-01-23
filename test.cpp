#include <iostream>
#include <string>
using namespace std;

//手机类
class Phone
{
public:
    Phone(string pBrand)//构造函数
    {
        m_Brand = pBrand;
    }
    string m_Brand;
};

//人  类
class Person
{
public:
    //相当于Phone m_Phone = pName;以下是一种隐式转换
    Person(string name, string pName):m_Name(name),m_Phone(pName)
    {

    }
    string m_Name;
    Phone m_Phone;
};

void test01()
{
    Person p("张三", "iPhone114514");
    cout << p.m_Name << "拿着" << p.m_Phone.m_Brand;
}

int main()
{
    test01();
    return 0;
}
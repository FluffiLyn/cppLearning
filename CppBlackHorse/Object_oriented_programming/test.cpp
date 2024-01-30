#include <iostream>
#include <string>
using namespace std;

//建筑物类
class Building;//声明
class GoodGay
{
public:
    GoodGay();//声明

    void visit();//参观函数 访问Building中的属性

    Building * building;
};

class Building
{
    
    friend class GoodGay;

public:
    Building();

    string m_SittingRoom;//客厅

private:
    string m_BedRoom;//卧室
};

//可以类内声明，类外写成员函数
GoodGay::GoodGay()
{   //由于GoodGay内的Building变量是指针，所以要用new的方法返回该对象的指针
    building = new Building;
}

//类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

void GoodGay::visit()
{
    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}

int main()
{
    GoodGay gg;
    gg.visit();

    return 0;
}

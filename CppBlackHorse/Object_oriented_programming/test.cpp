#include <iostream>
#include <string>
using namespace std;

//建筑物类
class Building
{
    //goodGay全局函数是Building的友元，可以访问Building的私有成员
    friend void goodGay(Building *building);
public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;//卧室

};

//全局函数
void goodGay(Building *building)//好基友
{
    cout << "好基友全局函数正在访问：" << building->m_SittingRoom << endl;
    //若没有前面的friend，则下一行代码会报错。
    cout << "好基友全局函数正在访问：" << building->m_BedRoom << endl;
    
}


//常对象
void test01()
{
    Building building;
    goodGay(&building);
}

int main()
{
    test01();

    return 0;
}

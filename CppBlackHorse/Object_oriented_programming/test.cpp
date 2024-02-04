#include <iostream>
using namespace std;

class AbstractDrinks
{
public:
    //煮水
    virtual void Boil() = 0;

    //冲泡
    virtual void Brew() = 0;

    //倒入杯中
    virtual void pourIn() = 0;

    //加入辅料
    virtual void putIn() = 0;
    
    void makeDrink()
    {
        Boil();
        Brew();
        pourIn();
        putIn();
    }
};

//制作咖啡
class Coffee :public AbstractDrinks
{
public:
    //煮水
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }

    //冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }

    //倒入杯中
    virtual void pourIn()
    {
        cout << "倒入杯中" << endl;
    }

    //加入辅料
    virtual void putIn()
    {
        cout << "加入糖和牛奶" << endl;
    }
};

//制作茶
class Tea :public AbstractDrinks
{
public:
    //煮水
    virtual void Boil()
    {
        cout << "煮怡宝" << endl;
    }

    //冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }

    //倒入杯中
    virtual void pourIn()
    {
        cout << "倒入茶杯中" << endl;
    }

    //加入辅料
    virtual void putIn()
    {
        cout << "加入枸杞" << endl;
    }
};

//由于抽象类不能实例化，故这里用指针
void doWork(AbstractDrinks * abs)
{
    abs->makeDrink();
    delete abs;
}

//AbstractDrinks * abs = new Coffee
//自己写项目千万别这样写，除非你想内存泄漏

void test01()
{
    //制作咖啡
    doWork(new Coffee);

    //制作茶
    doWork(new Tea);
}

int main()
{
    test01();

    return 0;
}
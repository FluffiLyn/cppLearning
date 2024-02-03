#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    virtual void sound()
    {
        cout << "动物在叫" << endl;
    }
};

//猫
class Cat :public Animal
{
public:
    void sound()
    {
        cout << "猫在叫" << endl;
    }
};

//执行动物“叫唤”的函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行“猫在叫”，则这个函数地址需要在运行阶段进行绑定。
void makeSound(Animal &animal)
{
    animal.sound();
}

void test01()
{
    Cat cat;
    //传入的是Cat类
    //因为c++允许父子之间的类型转换（父类可转子类，而子类不可转父类）
    //此时调用的是父类Animal的sound()函数
    makeSound(cat);
}

int main()
{
    test01();

    return 0;
}
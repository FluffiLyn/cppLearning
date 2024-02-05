#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:

    Animal()
    {
        cout << "Animal的构造函数调用" << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal的析构函数调用" << endl;
    }
    virtual void speak() = 0;
};

class Cat :public Animal
{
public:

    Cat(string name)
    {
        cout << "Cat的构造函数调用" << endl;
        m_Name = new string(name);
    }
    
    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout << "Cat的析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    virtual void speak()
    {
        cout << *m_Name << "猫在说话" << endl;
    }

    string *m_Name;
};

void test01()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构的时候，不会调用子类的析构函数
    //导致子类如果有堆区属性，会出现内存泄漏
    //所以我们要在Animal类的析构函数前加virtual，使其变为虚析构
    //如果不理解，可以尝试把virtual去掉，看运行结果有什么不同
    delete animal;
}

int main()
{
    test01();

    return 0;
}
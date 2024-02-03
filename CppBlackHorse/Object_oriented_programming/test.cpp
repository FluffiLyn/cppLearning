#include <iostream>
#include <string>
using namespace std;

//计算器抽象类
class AbsCalculator
{
public:

    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;

};

//加法计算器类
class AddCalculator :public AbsCalculator
{
public:

    int getResult()
    {
        return m_Num1 + m_Num2;
    }

};

//减法计算器类
class SubCalculator :public AbsCalculator
{
public:

    int getResult()
    {
        return m_Num1 - m_Num2;
    }

};

//减法计算器类
class MulCalculator :public AbsCalculator
{
public:

    int getResult()
    {
        return m_Num1 * m_Num2;
    }

};

void test01()
{
    //多态使用条件：父类指针或引用指向子类对象
    //这里我们用指针

    //创建加法计算器对象
    AbsCalculator * abc = new AddCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;

    //减法运算
    //还是这个父类的指针，只不过改变指向的对象
    abc = new SubCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
}

int main()
{
    test01();

    return 0;
}
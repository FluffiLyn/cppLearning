# 类和对象
c++面向对象的三大特性为：***封装、继承、多态***

c++认为万事万物皆为对象，对象有其属性和行为。

具有相同性质的对象，我们可以抽象成***类***。
* 例如，人属于人类，具有姓名、年龄等属性，有走、跑等行为。

## 1. 封装

### 1.1 封装的意义

* 将属性和行为作为一个整体，表现生活中的事物；
* 将属性和行为加以权限控制。

#### 意义一：基本语法：
```c++
class className
{ 
    accessSpecifier://访问权限-private, public or protected
    dataMembers;    //属性-variables to be used
    memberFunctions(){} //行为-methods to access data members
};
```

\
例：创建一个圆类，求具体圆对象的周长。
```c++
#include <iostream>
using namespace std;

const double PI = 3.14;//定义圆周率

class Circle//类名一般首字母大写，增加可读性
{
    public:
    int m_r;//属性：半径

    double Circumference()//行为（或成员函数）：获取圆的周长
    {
        return 2 * PI * m_r;
    }
};

int main()
{
    Circle c1;//通过Circle类创建具体的圆
    c1.m_r = 10;//给c1的m_r属性赋值

    cout << "The circumference of this circle is: " << c1.Circumference() << endl;

    return 0;
}
```

#### 意义二：三种访问权限：

* **public** 公共权限————成员 类内可以访问，类外也可以访问。

* **protected** 保护权限————成员 类内可以访问，类外不可访问；子类可访问父类的私有内容。

* **private** 私有权限————成员 类内可以访问，类外不可访问；子类不能访问父类的私有内容。



例：封装的权限控制：
```c++
/*Wanging: this code is buggy.*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string m_Name;//姓名

protected:
    string m_Car;//汽车

private:
    int m_Pswd;//银行卡密码

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "劳斯莱斯";
        m_Pswd = 114514;
    }
};


int main()
{
    Person p1;
    p1.m_Name = "李四";
    p1.m_Car = "拖拉机";//无法访问
    p1.m_Pswd = 1919810;//无法访问

    p1.func();//无法调用
}
```
### 1.2 struct和class的区别

唯一区别就在于***默认的访问权限不同***。
* struct 默认权限为公共
* class 默认权限为私有

### 1.3 成员属性设置为私有的好处

优点1：将所有成员属性设为私有，可以自己控制读写权限。\
优点2：对于写权限，我们可以检测数据的有效性。

例：
```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
public://创建一个对外的“接口”
    
    //设置姓名的函数
    void setName(string name)
    {
        m_Name = name;
    }
    
    //读取姓名的函数
    string getName()
    {
        return m_Name;
    }

    //获取年龄
    int getAge()
    {
        m_Age = 0;//初始化为0
        return m_Age;
    }

    //设置情人
    voidsetLover(string lover)
    {
        m_Lover = lover;
    }

}

private:
{
    string m_Name;//姓名 可读可写
    int m_age;//年龄 只读
    string m_Lover;//对象 只写 
};

int main()
{
    Person p1;
    p1.setName("张三");

    cout << "姓名为：" << p1.getName() << endl;
    cout << "年龄为：" << p1.getAge() << endl;
    //p.setAge();
    //没有给出setAge函数，故无法修改

    p.setLover("大力王byd");
    //cout << "情人为：" << p1.getLover() << endl;
    //没有给出getLover函数，故无法访问

    return 0;
}
/*如果要检测数据的有效性，可以在public创建函数，然后在函数内用if判断*/
```
###  练习：判断点和圆的关系
```c++
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point//定义一个点类
{
public:
    //设置x的值
    void setX(int x)
    {
        m_X = x;
    }
    //获取x
    int getX()
    {
        return m_X;
    }
    //设置y的值
        void setY(int y)
    {
        m_Y = y;
    }
    //获取y
    int getY()
    {
        return m_Y;
    }

private:
    int m_X;
    int m_Y;
};


class Circle
{
public:
    //设置半径
    void setR(int r)
    {
        m_R = r;
    }
    //获取半径
    int getR()
    {
        return m_R;
    }
    //设置圆心
    void setCenter(Point center)
    {
        m_Center = center;
    }
    //获取圆心
    Point getCenter()
    {
        return m_Center;
    }

private:
    int m_R;//半径
    
    Point m_Center;//圆心
                   //类的嵌套
};

//判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
     
    //计算两点之间距离的平方
    int dSqrt =
    pow((c.getCenter().getX() - p.getX()), 2) + 
    pow((c.getCenter().getY() - p.getY()), 2);

    //计算半径的平方
    int rSqrt = pow(c.getR(), 2);

    if(dSqrt == rSqrt)
    {
        cout << "点在圆上" << endl;
    }
    else if(dSqrt > rSqrt)
    {
        cout << "点在圆外" << endl;
    }
    else
        cout << "点在圆内" << endl;    
}

int main()
{
    Circle c;
    
    c.setR(10);
    
    //创建(10,10)的圆心
    Point center;
    center.setX(10);
    center.setY(10);
    c.setCenter(center);

    //创建点
    Point p;
    p.setX(10);
    p.setY(11);

    isInCircle(c,p);

    return 0;
}
```

*注：可以把class扔进一个头文件xxx.h中，在cpp文件中用#include "xxx.h"来使用。*

* 头文件中的class中的成员函数仅需声明，在cpp文件中再定义。

```c++
/*xxx.h*/
#pragma once//防止重复引用
#include <iostream>
using namespace std;

class Circle
{
public:
    void setX(int x);
private:
    int m_X;
    int m_Y;
};
```
```c++
/*xxxx.cpp*/
#include "xxx.h"
void Circle::setX(int x)//代表setX是Circle作用域的函数
{
    m_X = x;
}
```

## 2. 对象的初始化和清理

生活中我们买的电子产品基本会有出厂设置，在某一天我们不用的时候也会删除一些数据来保证安全。

c++中的每个对象也会有初始设置，以及对象销毁前的清理数据的设置。

### 2.1 构造函数和析构函数
对象的初始化和清理也是两个非常重要的**安全**问题。
* 一个对象或者变量如果没有***初始状态***，对其使用的后果未知；
* 使用完一个对象或变量，没有及时清理，也会造成一定的安全问题。

c++利用了***构造函数***和解析函数解决上述问题，这两个函数将会被编译器自动调用，完成对象的***初始化和清理***工作。该工作是编译器强制要我们做的事情，如果我们不提供构造和析构，编译器会提供空实现。

* **构造函数**：主要用于在创建对象时为对象的成员属性赋值。构造函数由编译器自动调用，无需手动调用。
* **析构函数**：在对象销毁前系统自动调用，执行清理工作。

构造函数语法：`ClassName(){}`
* 没有返回值，也不写void；
* 函数名称与类名相同；
* 构造函数可以有参数，因此可以重载；
* 程序在调用对象的时候会自动调用构造，无需手动调用，而且只会调用一次。

析构函数语法：`~ClassName(){}`
* 没有返回值，也不写void；
* 函数名称与类名相同且在前面加上~；
* 析构函数**不可以**有参数，因此不能重载；

\
例1：构造函数
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person构造函数的调用" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};

//创建对象
void test01()
{
    Person p;//在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{
    test01();

    Person pp;
    
    system("Pause");
    return 0;
}

```
```c++
/*输出结果：

Person构造函数的调用
Person析构函数的调用
Person构造函数的调用
Press any key to continue . . . 
Person析构函数的调用

说明在创建对象时构造函数自动调用了，
并且p在test01()执行完之后被销毁，
而pp在main函数执行完之后才被销毁*/
```

### 2.2 构造函数的分类及调用

两种分类方式：
* 按参数分为**有参构造**和**无参构造**。
* 按类型分为**普通构造**和**拷贝构造**。

三种调用方式：
* 括号法
* 显示法
* 隐式转换法

例：
```c++

```

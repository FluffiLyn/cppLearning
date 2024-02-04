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

（注：c++11开始，struct可以修改权限，也有封装、继承和多态的特性）

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
    void setLover(string lover)
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
#include <iostream>
using namespace std;

class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;   
    }
    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    //拷贝构造函数
    Person( const Person &p)//必须加const，而且后面是地址传递
    {
        //将传入的人身上的所有属性拷贝到我身上
        age = p.age;
        cout << "拷贝函数调用" << endl; 
    }

    int age;
};

//调用
void test01()
{
    Person p1;//默认构造函数调用(不要有括号，否则会被编译器认为是函数声明)
    
    //1.括号法
    Person p2(10);//调用有参构造函数
    Person p3(p2);//调用拷贝构造函数
    
    cout << "p2的年龄为：" << p2.age << endl;
    cout << "p3的年龄为：" << p3.age << endl;//p2的age被拷贝到了p3
    
    //2.显示法
    Person p11;
    Person p22 = Person(10);//有参构造
    Person p33 = Person(p22);//拷贝构造 
    //注：Person(10)会创建一个匿名对象。特点：当前行执行结束后，系统会立即回收该对象
    //并且不要用拷贝构造函数来初始化匿名对象，否则系统会报错：重定义
    
    //3.隐式转换法
    Person p4 = 10;//会转换成Person p4 = Person(10)//有参构造
    Person p5 = p4;//拷贝构造

/*以上三种方法可任选一种使用*/
}
int main()
{
    test01();

    return 0;
}

```

### 2.3 拷贝构造函数的调用时机
当以拷贝的方式初始化对象时会调用拷贝构造函数，这里需要注意两个关键点，分别是以***拷贝的方式***和***初始化对象***。初始化对象是指，为对象分配内存后第一次向内存中填充数据，这个过程会调用构造函数，对象被创建后必须立即初始化。也就是说***只要创建对象就会调用构造函数***。

三种情况：
* 使用一个已创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象

例：
```c++
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
```

### 2.4 构造函数调用规则
默认情况下，c++编译器至少给一个类添加3个函数
* 默认构造函数（无参，函数体为空）
* 默认析构函数（无参，函数体为空）
* 默认拷贝构造函数，对属性进行值拷贝 

调用规则如下：
* 如果用户有定义有参构造函数，c++不会再提供默认无参构造，但是会提供默认拷贝构造
* 如果用户自定义拷贝构造函数，c++不会再提供其他构造函数

不放例子了，之前有提过。

### 2.5 深拷贝和潜拷贝
<font color=red>***面试经典问题之一***</font>

浅拷贝：简单的赋值拷贝操作

深拷贝：在堆区中重新申请空间，进行拷贝操作

例：
```c++
//沿用上一节的类
public:
    Person(int age, int height)
    {
        m_Age = age;
        new int(height);//堆区数据由程序员手动创建，在析构函数被调用前要手动释放
        cout << "Person的有参构造函数调用" << endl;
    }

    ~Person()//析构函数
    {
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;//防止野指针出现
        }
    }
```
* 如果利用编译器提供的拷贝构造函数，将会执行浅拷贝操作。

### 2.6 初始化列表
语法：`构造函数(): 属性1(值1), 属性2(值2)...{}`\
例:
```c++
#include <iostream>
using namespace std;
class Person
{
public:
    /*传统初始化操作
    Person(int a, int b, int c)
    {    
        m_A = a;
        m_B = b;
        m_C = c;
    }*/
    
    //初始化列表
    Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
    {}

    int m_A;
    int m_B;
    int m_C;
};

void test01()
{

    Person p(10, 20, 30);
    cout << p.m_A << endl;
    cout << p.m_B << endl;
    cout << p.m_C << endl;
}

int main()
{
    test01();
    return 0;
}
```
使用初始化列表的好处：
* 1. 类成员中存在常量时，只能初始化而不能赋值。
* 2. 类成员存在引用时，也只能初始化。
* 3. 在大型项目中，类中成员变量极多的情况下，初始化列表的效率更高。

### 2.7 类对象作为成员
成员可以使另一个类的对象，我们称该成员为对象成员。如：
```c++
class A{};
class B
{
    A a;
}
```
例：
```c++
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
```
当其他类对象作为本类的成员时，其他类对象的构造函数先于本类完成执行

### 2.8 静态成员
静态成员就是在成员变量、函数前加上static。
* 静态成员变量
    * 所有对象共享同一份数据
    * 在编译阶段分配内存
    * ***类内***声明，***类外***初始化 

* 静态成员函数
    * 所有对象共享同一个函数
    * 静态成员函数只能访问静态成员变量

例1：静态成员变量
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    //类内声明
    static int m_A;
};

//类外初始化。要写Person作用域。
int Person::m_A = 114514;

void test01()
{
    Person p;
    cout << p.m_A << endl;

    //通过p2来修改m_A数据，再通过p访问m_A
    Person p2;
    p2.m_A = 200;
    
    //会发现p的m_A也被修改了，从而说明所有对象共享同一份数据
    cout << p.m_A << endl;
}

void test02()
{
    //静态成员变量有两种访问方式
    //1、通过对象进行访问
    //Person p;
    //cout << p.m_A << endl;
    
    //2、通过类名进行访问
    cout << Person::m_A << endl;
}

int main()
{
    test01();
    return 0;
}
```
例2：静态成员函数
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    //静态成员函数
    static void func()
    {
        m_A = 100;//静态成员函数可以访问 静态成员变量
        //m_B = 200; 会报错。不可访问 非静态成员变量
        cout << "静态成员函数调用" << endl;
    }
    static int m_A;//静态成员变量
    int m_B;//非静态！！此变量属于特定的对象，func()不知道为哪一个对象的m_B赋值，于是会报错
}

void test01()
{
    //1、通过对象访问（与例1类似）
    //2、通过类名访问
    Person::func();
}

int main()
{
    test01();
    return 0;
}
```
## 3. c++对象模型和this指针

### 3.1 成员变量和成员函数分开存储
类内的的成员变量和成员函数分开存储。只有非静态成员才属于类的对象上。\
例：
```c++
#include <iostream>
using namespace std;

class Person1{};//空类

void test01()
{
    Person1 p1;
    //空对象占用内存空间是 1
    //c++编译器会给每个空对象也分配一个字节空间，为了区分空对象站内存的位置。
    //每个空对象也有一个独一无二的内存地址
    cout << "Size of p is "<< sizeof(p1) << endl;
}

class Person2
{
    int m_A;//非静态成员变量 属于类对象上
    static int m_B;//静态成员变量 不属于类对象上
    void func(){}//非静态成员函数 不属于类对象上
};
int Person2::m_B = 114514;

void test02()
{
    Person2 p2;
    //此处输出4，包括m_A的长度，不包括m_B和func()的长度。
    cout << "Size of p2 is " << sizeof(p2) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}

```

### 3.2 this指针概念
this指针指向被调用的**成员函数**所属的对象。它不需要定义，可直接使用。它被隐含在每一个非静态成员函数内。\
\
用途：
* 当**形参**和**成员**变量同名时，可用this指针区分。
* 在类的**非静态**成员函数中返回对象本身，可用return *this。\

例:
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = age;//this指向的age是成员变量age，与形参age区分开来
    }
    int age;

    Person& PersonAddAge(Person &p)
    {
        //将另一个“人”的年龄加到自己年龄上（好怪哦）
        this->age += p.age;
        
        //this是指向p2的指针，*this是p2本体
        return *this;
    } 
};

//1、解决名称冲突
void test01()
{
    Person p1(10);
    cout << "p1的年龄为" << p1.age << endl;
}

//返回对象本身用*this
void test02()
{
    Person p1(10);
    Person p2(10);

    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//加三次
    cout << "p2的年龄为" << p2.age << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}
```
注意：对于PersonAddAge函数，如果前面是值传递而非引用传递，则后面输出p2的结果是20。这是因为***值传递会创建新的对象，而引用传递则直接操作原始对象***，第一次调用p2.PersonAddAge(p1)时，实际上是将p2和p1的age相加得到20，然后返回一个***新的Person对象p（其age为20）***（实际上这个对象的名称是未知的，也不重要），但这个新的对象并没有赋值给p2，所以p2的age仍然是初始值10。接着连续调用PersonAddAge函数两次，每次都是将新的Person对象p（age为20）与p1的age相加，结果都是20，然后将结果返回给一个新的Person对象p，但这些新的对象并没有赋值给p2，所以p2的age仍然是20。

### 3.3 空指针访问成员函数
c++空指针可以调用成员函数，但是要注意有没有用到this指针。如果有，需要加以判断，保证代码的健壮性。 \
例：
```c++
#include <iostream>
using namespace std;

class Person
{
public:

    void showClassName()
    {
        cout << "This is Person class." << endl;
    }

    void showPersonAge()
    {
        cout << "Age = " << m_Age << endl;
    }
    int m_Age;
   
};


void test01()
{
    Person * p = NULL;
    p->showClassName();//不会报错
    //p->showPersonAge();//会报错
}

int main()
{
    test01();
    return 0;
}

```
p->showPersonAge()报错的原因是：该函数内的m_Age是默认为this->m_Age的，而this指针（也即p）是空的，因此报错
* 为了防范此bug，我们可以用if判断是否为空指针，若为指针直接return。

### 3.4 const修饰成员函数
1.常函数
* 被const修饰的成员函数就叫常函数
* 常函数内**不可以**修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

2.常对象
* 被const修饰的对象称为常对象
* **常对象只能调用常函数**

例:
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    //常函数
    //在成员函数后加const，实际上修饰的是this指针的指向。
    void showPerson() const 
    {
        //this->m_A = 100;//会报错
        this->m_B = 100;//不会报错
    }

    //普通成员函数
    void func()
    {}

    int m_A;
    mutable int m_B;//const不允许我改？诶，给你加个mutable！
};


void test01()
{
    Person p;
    p.showPerson();
}

//常对象
void test02()
{
    const Person p;
    //p.m_A = 100;//会报错
    p.m_B = 100;//不会报错

    //p.func();//会报错
    p.showPerson();//不会报错
}

int main()
{
    test01();
    test02();
    return 0;
}

```
* this指针的本质是**常量指针**，它指向的内容不可修改。

## 4. 友元
在程序中 ，有些私有属性需要让类外的一些函数或者类进行访问，就需要运用友元技术。

友元的目的是让一个函数或者类访问领一个类中私有成员。它的关键字是friend。

友元的三种实现：
* 全局函数做友元
* 类做友元
* 成员函数做友元

例1：全局函数做友元
```c++
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
```
例2：类做友元
```c++
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
    friend class GoodGay;//类做友元

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
```
例3：成员函数做友元

```c++
class Building
{
    friend void visit();
}
```

## 5. 运算符重载

### 5.1 加号运算符重载
作用：实现两个自定义数据类型相加的运算。

例1：成员函数重载+号
```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;//this指的是.operator+(p)前面的对象
        temp.m_B = this->m_B + p.m_B;
        return temp;//不能返回引用，因为temp会被销毁，此时引用是空指针
    }

    int m_A;
    int m_B;

};

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    //本质：Person p3 = p1.operator+(p2);
    Person p3 = p1 + p2;
    
    cout << "p3.m_A=" << p3.m_A << endl;
    cout << "p3,m_B=" << p3.m_B << endl;
}

int main()
{
    test01();  

    return 0;
}
```
例2：全局函数重载+号
```c++
//本质：Person p3 = operator+(p1, p2);
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
```
注：
* 运算符重载也可以发生函数重载。你可以再次将它定义，例如Person operator+(Person &p1, int x)。
* 内置的运算符不可改变
* 不要乱写重载的内容。比如加法重载里面写个减法的内容，造孽啊！

### 5.2 左移运算符重载
作用：输出自定义数据类型。

例：
```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream &cout, Person &p);

public:
    
    //利用成员函数重载 左移运算符
    //一般不会这么做，因为无法实现cout在左侧
    //void operator<<(cout){};

    int m_A;
    int m_B;

private:
    int m_C = 10;
};

//利用全局函数重载左移运算符
//本质：operator<<(cout,p);，简化成cout << p
//一定要用引用传入cout，因为cout对象只能有一个。
//如果想用链式编程思想在后面继续输出，<<重载就必须返回cout，重载函数前面不能写成void
ostream & operator<<(ostream &cout, Person &p)
{
    cout << "m_A = " << p.m_A << " m_B = " << p.m_B
        << " m_C = " << p.m_C;
    return cout;
}

void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 10;

    //重载<<之后以下语句就能正常执行
    cout << p << endl;
}

int main()
{
    test01();  

    return 0;
}

```
注：
* 1、cout用于在计算机屏幕上显示信息，是C++中ostream类型的***对象***，C++的输出是用“流” (stream)的方式实现的，流运算符的定义等信息是存放在C++的输入输出流库中的，因此如果在程序中使用cout和流运算符，就必须使用预处理命令把头文件stream包含到本文件中，即< iostream >库，该库定义的名字都在命名空间std中，所以·cout全称是std::cout 。

* 2、对于ostream & operator<<(ostream &cout, Person &p)，用函数指针的原因是：ostream对象通常不允许通过拷贝构造函数进行复制，而直接返回ostream对象时会触发拷贝构造函数的调用。

* 3、所有的重载都最好是***全局函数重载***，这样便于规范代码，否则会有局限性。

### 5.3 自增运算符重载
作用：实现自己的整型数据。

例1：重载前置++运算符
```c++
class MyInteger
{
public:
    MyInteger()
    {
        m_Num = 0;
    }

    int m_Num;
}

//重载前置++运算符
MyInteger & operator++()
{
    //先进行++运算
    ++m_Num;
    
    //再将自身返回
    return *this;
}
```
例2：重载后置++运算符
```c++
class MyInteger
{
public:
    MyInteger()
    {
        m_Num = 0;
    }

    int m_Num;
}

//重载后置++运算符
//int代表占位参数，用于区分前置和后置递增
MyInteger operator++(int)
{
    //先记录当时结果
    MyInteger temp = *this;
    //后递增
    m_Num++;
    //最后记录的结果返回
    return temp;
}
```
注：
两个函数的返回类型不同。前置++返回的是引用，而后置++返回的是值。

在c++中，
* ++a表示取a的地址，增加它的内容，然后把值放在寄存器中；
* a++表示取a的地址，把它的值装入寄存器，然后增加内存中的a的值；

假设a=0，那么(a++)++可以通过编译，但是它输出的值是1，具体原因已在章节3.2解释过。

### 5.4 赋值运算符重载

c++编译器至少给一个类添加4个函数：
* 默认构造函数
* 默认析构函数
* 默认拷贝构造函数
* 赋值运算符operator=，对属性进行值拷贝

使用这个默认的赋值运算符操作类对象时，该运算符会把这个类的所有数据成员都进行一次赋值操作。

如果类中有属性指向堆区(如new了一个指针)，那么会出现堆区内存重复释放的问题，如：
```c++
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    int *m_Age;
};
 
int main()
{
    Person p1(10);
    Person p2(20);
    p2 = p1;
    
    cout << "p1的年龄是：" << *p1.m_Age << endl;
    cout << "p2的年龄是：" << *p2.m_Age << endl;
    return 0;
}
```
在默认的赋值运算符函数中，它会进行**浅拷贝**操作，即只是简单地将p1的成员变量值复制给p2的成员变量。由于m_Age是一个指向动态分配内存的指针，浅拷贝只会复制指针的值，

所以，在这段代码中，p2的m_Age指针与p1的m_Age指针指向了同一块内存地址。当p2的析构函数被调用时，会释放这块内存，而p1的m_Age指针仍然指向已经被释放的内存地址。

因此，当尝试打印p1.m_Age和p2.m_Age的值时，由于p1.m_Age指向的内存已经无效，访问它会导致程序崩溃。

解决方法：利用赋值运算符重载进行**深拷贝**。

例：
```c++
Person & operator=(Person &p)
{
    //先判断是否有属性在堆区，若有，则先释放干净，后深拷贝
    if (m_Age != NULL)
    {
        delete m_age;
        m_Age = NULL;
    }

    m_Age = new int(*p.m_Age);   
    
    return *this; 
}
```

### 5.5 关系运算符重载
作用：让两个自定义对象进行对比操作。

例：
```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    string m_Name;
    int m_Age;

    //请思考：为什么这里不用引用
    bool operator==(Person &p)
    {
        if(m_Name == p.m_Name && m_Age == p.m_Age)
        return true;
        return false;
    }
};


void test01()
{
    Person p1("Tom", 18);
    Person p2("Jerry", 18);

    if (p1 == p2)
    {
        cout << "p1 equals to p2." << endl;
    }
    else
    {
        cout << "They are not equal." << endl;
    }
}

int main()
{
    test01();
    return 0;
}
```

类似地，也可以写`bool operator!=(Person &p)`

### 5.6 函数调用运算符重载
* 函数调用运算符()也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为仿函数
* 仿函数没有固定写法

例：
```c++
#include <iostream>
#include <string>
using namespace std;

//打印输出类
class MyPrint
{
public:

    //重载函数调用运算符
    void operator()(string text)
    {
        cout << text << endl;
    }

};

void MyPrint02(string text)
{
    cout << text << endl;
}

void test01()
{
    MyPrint print;
    print("Hello world!");//仿函数
    
    MyPrint02("Hello world!");//函数
}

int main()
{
    test01();

    return 0;
}

```
当然，你也可以这样调用：
```c++
cout << MyPrint()("Hello world!");
```
这个被称为匿名函数对象，执行完这一行后就会被销毁。

## 6. 继承
就像生物学的物种分类一样，有些类与类之间存在一些关系：下级成员拥有上一级的共性，还有自己的特性。

此时我们可以考虑利用继承的技术，减少**重复代码**。

### 6.1 继承的基本语法
`class 子类 : 继承方式 父类`

错误示范：
```c++
#include <iostream>
#include <string>
using namespace std;

//普通实现页面

//Java教程页面
class Java 
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共header）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共footer）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};

//Python页面
class Python 
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共header）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共footer）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

//C++页面
class Cpp 
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共header）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共footer）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};

void test01()
{
    cout << "Java下载视频页面如下：" << endl;
    Java jvav;
    jvav.header();
    jvav.footer();
    jvav.left();
    jvav.content();

    cout << "---------------------------" << endl;
    cout << "Python下载视频页面如下：" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "---------------------------" << endl;
    cout << "C++下载视频页面如下：" << endl;
    Cpp cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

int main()
{
    test01();
    return 0;
}
```
cv工程师，你好

正确示范：使用继承
```c++
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共header）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共footer）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
};

//Java页面
class Java:public BasePage//继承
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};
//其余同理
```

### 6.2 继承方式
public, protected, private.

* 1、子类无法访问父类private内容
* 2、公有继承：父类的public和protected都原封不动地继承至子类
* 3、保护继承：父类的public和protected继承至子类后都是protected
* 4、私有继承：父类的public和protected继承至子类后都是private

### 6.3 继承中的对象模型
父类中**所有非静态成员属性**都会被子类继承。

父类中的私有成员属性被编译器隐藏了，因此**无法访问**，但是**会被继承下去**。

可以用sizeof(ClassName)来验证。

### 6.4 继承中构造和析构顺序
父构->子构->子析->父析

遵循FILO（先进后出）（doge

### 6.5 继承同名成员处理方式
问题：当子类与父类出现同名的**成员**，如何通过子类对象，访问子类火父类中同名的数据呢？

答：
* 访问子类同名成员 直接访问即可
* 访问父类同名成员 需要加作用域

```c++
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base的func()调用" << endl;
    }
    
    void func(int a)
    {
        cout << "Base的func(int a)调用" << endl;
    }
    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "Son的func()调用" << endl;
    }

    int m_A;
};

//同名成员属性处理
void test01()
{
    Son s;
    cout << "Son m_A = " << s.m_A << endl;
    cout << "Base m_A = " << s.Base::m_A << endl;
}

//同名成员函数处理
void test02()
{
    Son s;
    s.func();//子类成员函数
    s.Base::func();//父类成员函数1
    s.Base::func(114514);//父类成员函数2
}

int main()
{
    test01();
    test02();
    return 0;
}
```

### 6.6 多继承语法
C++允许一个类继承多个类。

语法:`class 子类 : 继承方式 父类1, 继承方式 父类2, ...`

多继承可能引发父类中有同名成员出现，需要加作用域区分

**实际开发中不建议用多继承**。

例：
```c++
#include <iostream>
using namespace std;

class Base1
{
public:

    Base1()
    {
        m_A = 100;
    }
    int m_A;
};

class Base2
{
public:

    Base2()
    {
        m_B = 200;
    }
    
    int m_A;
    int m_B;
};

class Son:public Base1, public Base2
{
public:

    Son()
    {
        m_C = 300;
        m_D = 400;
    }

    int m_C;
    int m_D;
};

void test01()
{
    Son s;
    cout << "sizeof(s) = " << sizeof(s) << endl;
    cout << "m_A = " << s.m_A << endl;
    cout << "m_A = " << s.Base1::m_A << endl;
}


int main()
{
    test01();

    return 0;
}
```

### 6.7 菱形继承
概念：两个子类（派生类）继承同一个父类（基类），又有一个类同时继承两个子类。又称钻石继承。

例：
```c++
#include <iostream>
using namespace std;

//动物类
class Animal
{
public:

    int m_Age;
};

//羊类
class Sheep:public Animal{};

//驼类
class Camel:public Animal{};

//羊驼类
class Alpaca:public Sheep, public Camel{};

void test01()
{
    Alpaca alp;
    alp.Sheep::m_Age = 18;
    alp.Camel::m_Age = 28;

    cout << "alp.Sheep::m_Age = " << alp.Sheep::m_Age << endl;
    cout << "alp.Camel::m_Age = " << alp.Camel::m_Age << endl;
}


int main()
{
    test01();

    return 0;
}
```
（注：生物学上，羊驼和羊几乎没有亲缘关系，而与骆驼有很很大关系。本例仅以字面意义来演示菱形继承）（逃

在上面的示例代码中，Sheep类和Camel类都继承了Animal类的m_Age属性，导致两个子类的m_Age重复了，使得资源浪费。

为了避免此类浪费，我们可以使用关键字virtual，即**虚继承**，可解决菱形继承带来的资源浪费。
* 此时Animal类称为虚基类


```c++
class Sheep:virtual public Animal{};
class Camel:virtual public Animal{};
```
访问方式直接写成如下形式
```c++
cout << alp.m_Age;
```

**原理：** 虚继承后，派生类多了一个vbptr（virtual base pointer），称为***虚基类指针***，它指向虚基类表（vbtable）。vbtable包含了偏移量信息，这些信息指示了虚基类相对于派生类对象起始地址的偏移量。通过这种机制，即使在复杂的继承体系中，程序也能正确地定位和访问虚基类的成员。

## 7. 多态

### 7.1 多态的基本概念
多态指的是**同一个方法**调用，由于**对象不同**可能会有不同的行为。

多态分为两类：
* 1、静态多态：函数重载和运算符重载属于静态多态，复用函数名
* 2、动态多态：派生类和虚函数实现运行时多态

两者区别：
* 1、静态多态的函数地址早绑定————**编译**阶段确定函数地址
* 2、动态多态的函数地址晚绑定————**运行**阶段确定函数地址

例1：
```c++
#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    void sound()
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


//如果想执行“猫在叫”，则这个函数地址需要在运行阶段进行绑定。
void makeSound(Animal &animal)
{
    animal.sound();
}

void test01()
{
    Cat cat;
    makeSound(cat);
}

int main()
{
    test01();

    return 0;
}
```
其中，`void makeSound(Animal &animal)`是执行动物“叫唤”的函数。它的地址**早绑定**（在编译阶段确定函数地址）。调用makeSound时传入的是Cat类，这是合法的，因为c++允许父子之间的类型转换（父类可转子类，而子类不可转父类），然而此时调用的是**父类**Animal的sound()函数。

如果想执行“猫在叫”，则这个函数地址**晚绑定**（在运行阶段进行绑定）。也就是说，要利用虚函数来构成动态多态。

例2：
```c++
//将原cpp文件的Animal类修改为如下：
class Animal
{
public:
    virtual void sound()
    {
        cout << "动物在叫" << endl;
    }
};
//即可输出“猫在叫”
```
<details> <summary>（点击展开）ChatGPT解释</summary>
当函数makeSound被调用时，它使用的是动态绑定（即运行时绑定）机制。由于sound()函数在Animal类中被声明为virtual，编译器会根据实际对象的类型来确定调用的是哪个版本的sound()函数。因此，当你传入Cat对象时，实际上调用的是Cat类中重写的sound()函数，输出的是"猫在叫"。

如果将sound()函数声明为非虚函数（即没有virtual关键字），那么无论你传入什么类型的对象，都会调用Animal类中的sound()函数。因此，不管你传入的是Cat对象还是其他类型的对象，输出都是"动物在叫"。这是因为在编译阶段，函数的地址已经被确定下来，不会根据实际对象类型而改变。
</details>

\
当子类重写父类的虚函数时，子类的虚函数表内部会替换成子类虚函数的地址。

\
\
总结：
* 动态多态满足条件：
    * 1、有继承关系
    * 2、子类重写父类的虚函数
* 动态多态的使用：
    * 父类的指针或引用指向子类对象

### 7.2 多态案例一：计算器类
案例描述：分别利用普通写法和多态技术，设计一个计算器类，实现两个操作数进行运算。

多态的优点：
* 代码组织结构清晰，可读性强
* 便于前期和后期的扩展及维护

例1：普通实现
```c++
#include <iostream>
#include <string>
using namespace std;

class Calculator
{

public:
    
    int getResult(string oper)
    {
        if (oper == "+") return m_Num1 + m_Num2;
        else if (oper == "-") return m_Num1 - m_Num2;
        else if(oper == "*") return m_Num1 * m_Num2;

    }

    int m_Num1, m_Num2;
};

void test01()
{
    Calculator c;
    c.m_Num1 = 10;//操作数1
    c.m_Num2 = 10;//操作数2

    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
    cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}

int main()
{
    test01();

    return 0;
}
```
这里，我们没有写除法。如果想扩展新的功能，就要修改getResult()的源码。

在真正的开发中，这不是我们想要的结果。有时候一个方法包含上千行代码，如果直接从核心修改，那么修改量很大。我们可以从外面新增功能。

开发提倡**开闭原则**。
* 开闭原则：对扩展进行开放，对修改进行关闭。

例2：多态实现
```c++
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
```
如果要新增减法，我们可以新建减法类，然后重载getResult()函数。

总结：多态的优点：
* 代码组织结构清晰，可读性强
* 便于前期和后期的扩展及维护

### 7.3 纯虚函数和抽象类
在多态中，通常父类中的虚函数的实现是**毫无意义**的，主要功能是调用子类重写的内容，因此我们可以将虚函数改为**纯虚函数**。

纯虚函数语法：`virtual 返回值类型 函数名 (参数列表) = 0;`

当类中有这样的函数，那么这个类也被称为**抽象类**

抽象类的特点：
* 无法实例化对象
* 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

例：
```c++
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void func() = 0;
};

class Son :public Base
{
public:

    virtual void func()//有没有virtual都可以
    {
        cout << "func()调用" << endl;
    }

};

void test01()
{
    //Base b; new Base;
    //会报错，因为抽象类不允许实例化对象
    Son s;
    Base * base = &s;
    base->func();
}



int main()
{
    test01();

    return 0;
}
```

### 7.4 多态案例二：制作饮品
**案例描述：**
\
流程为：煮水-冲泡-导入杯中-加入辅料

```c++
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
//自己写项目千万别像下面这样写new，除非你想内存泄漏
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
```

### 7.5 虚析构和纯虚析构
多态使用时，如果子类有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码。

解决方法：将父类中的析构函数改为**虚析构**或**纯虚析构**
\
\
\
\
虚析构语法：`virtual ~类名(){}`

纯虚析构语法：`virtual ~类名() = 0`

二者的共性：
* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

二者的区别：
* 纯虚析构所属类为抽象类
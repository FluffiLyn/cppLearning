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



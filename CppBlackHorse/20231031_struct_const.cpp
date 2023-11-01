//Use "const" to make struct read-only, in order to prevent misoperations 
#include <iostream>
#include <string>
using namespace std;

struct stu
{
    string name;
    int age;
    int score;
};

void printStu1(stu s)
{
    cout << " 姓名：" << s.name << " 年龄：" << s.age << " 得分:" << s.score << endl;
}

void printStu2(stu *s)
{
    s->age = 150;//测试age是否会被改变
    cout << " 姓名：" << s->name << " 年龄：" << s->age << " 得分:" << s->score << endl;
}

void printStu3(stu *s)
{
    s->age = 150;//测试age是否会被改变
    cout << " 姓名：" << s->name << " 年龄：" << s->age << " 得分:" << s->score << endl;
}

void printStu3(const stu *s)//添加“const”，防止数据被修改
{
    s->age = 150;//测试age是否会被改变
    cout << " 姓名：" << s->name << " 年龄：" << s->age << " 得分:" << s->score << endl;
}

int main()
{
    struct stu s = {"蔡徐坤",15,70};

    printStu1(s);//值传递之前要先将数据复制一份再输出，且比较占内存，所以运行速度会慢，但是用指针传递就会快很多

    printStu2(&s);//地址传递就快很多，因为地址只占4个字节，不会复制新的副本出来节省内存空间

    cout << "main中蔡徐坤年龄为：" << s.age << endl;//原值为15，经过函数printStu2后age被修改为150

    s.age = 15;//改回来
    printStu3(&s);//运行这个就会报错，因为此时s是不可更改的，可以防止误操作

    return 0;
}



#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};


//1、值传递函数
void printStuInfo1(struct student s)
{
    cout << "值传递：姓名：" << s.name << "\t年龄：" << s.age << "\t分数：" << s.score << endl;
}

void printStuInfo2(struct student * p)
{
    cout << "地址传递：姓名：" << p->name << "\t年龄：" << p->age << "\t分数：" << p->score << endl;
}

int main()
{
    struct student a;
    a.name = "张三";
    a.age = 20;
    a.score = 85;

    printStuInfo1(a);

    printStuInfo2(&a);
    
    return 0;
}
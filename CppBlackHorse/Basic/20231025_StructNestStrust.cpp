#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;//姓名
    int age;//年龄
    int score;
};

struct teacher
{
    int id;//编号
    string name;//姓名
    int age;//年龄
    struct student stu;//嵌套一个“学生”的结构（可理解成老师辅导的学生）
};



int main()
{
    teacher t;
    t.id = 10086;
    t.name = "Kutto Yaki";
    t.age = 20;
    t.stu.name = "ZephAzure";
    t.stu.age = 18;
    t.stu.score = 100;

    cout << "老师姓名：" << t.name << "\n老师编号：" << t.id << "\n年龄：" << t.age << endl;
    cout << "老师辅导的学生的姓名：" << t.stu.name << endl;

    return 0;
}
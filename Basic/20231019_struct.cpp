//结构体(struct)属于用户自定义的数据类型，允许用户存储不同的数据类型（与class不同）
//可看成数据类型的集合

//语法： struct 结构体名 { 结构体成员列表 };

#include <iostream>
#include <string>
using namespace std;

struct Students//例：创建学生数据类型
{
    string name;
    int age;
    int score;
}st3;

int main()
{
    //创建具体的学生
    struct Students st1;//第一种定义方法
    st1.name = "裤头";
    st1.age = 114;
    st1.score = 514;

    cout << "姓名：" << st1.name << endl;
    cout << "年龄：" << st1.age << endl;
    cout << "分数：" << st1.score << endl;

    struct Students st2 = {"牛魔", 1919, 810};//第二种定义方法
    cout << "姓名：" << st2.name << endl;
    cout << "年龄：" << st2.age << endl;
    cout << "分数：" << st2.score << endl;

    //第三种：在创建结构体时顺便创建具体学生st3而不用struct Students st3;
    st3.name = "22 五山 。";
    st3.age = 0;
    st3.score = 0;
    cout << "姓名：" << st3.name << endl;
    cout << "年龄：" << st3.age << endl;
    cout << "分数：" << st3.score << endl;
    return 0;
}
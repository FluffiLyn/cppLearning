//结构体数组
//作用：将自定义的结构体放入数组中方便维护
//语法：struct 结构体名 数组名[元素个数] = { {}, {}, {}, ... };
 
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    struct Student stuArray[3] = //创建结构体数组
    {
        {"牛魔",18,100},
        {"酬宾",28,99},
        {"电棍",38,98}
    };

    stuArray[2].name = "老八";//给结构体数组中的元素赋值
    stuArray[2].age = 1145;
    stuArray[2].score = 60;

    for(int i = 0;i < 3;i++)//遍历所有元素
    {
        cout << "姓名：" << stuArray[i].name << " ";
        cout << "年龄：" << stuArray[i].age << " ";
        cout << "分数：" << stuArray[i].score << " " << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct student//学生
{
    string sName;
    int score;  
};



struct teacher//老师
{
    string tName;
    struct student sArray[5];
};

void allocateSpace(struct teacher tArray[], int len)//给老师和学生赋值的函数
{
    string nameSeed = "ABCDE";
    for(int i = 0; i < len; i++)
    {  
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        for(int j = 0; j< 5; j++)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            int random = rand() % 61 + 40;//输出40~100的随机成绩
            tArray[i].sArray[j].score = random;
        }
       
    }
}

void printInfo(struct teacher tArray[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << tArray[i].tName << endl;

        for(int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名：" << tArray[i].sArray[j].sName << 
                "考试分数:" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(0));

    struct teacher tArray[3];//创建三名教师的数组
    
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray,len);

    printInfo(tArray, len);

}
#include <iostream>
#include <string>
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

}

int main()
{
    struct teacher tArray[3];//创建三名教师的数组
    
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray,len);



}
#include <iostream>
using namespace std;
//野指针：指向非法内存空间的指针变量
//在程序中要避免野指针

int main()
{
    int * p = (int *)0x1100;   //int * p = (int *)0x1100;会报错   
    return 0;
}
#include <iostream>
using namespace std;
//在32位操作系统下，指针储存的地址占四个字节
//64位下则是八个字节

int main()
{
    int a = 10;
    int * p = &a;

    cout << "size of (int *) = " << sizeof(int *) << endl;//括号内的int *也可替换成p
    cout << "size of (int *) = " << sizeof(float *) << endl;
    cout << "size of (int *) = " << sizeof(double *) << endl;
    cout << "size of (int *) = " << sizeof(char *) << endl;
    cout << "size of (int *) = " << sizeof(long *) << endl;
    //输出结果都是8

    return 0;
}
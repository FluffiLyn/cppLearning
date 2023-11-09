#include <iostream>
using namespace std;
//利用指针函数参数，可以修改实参的值

 void swap01(int a, int b)//值传递，不改变实参的值（仅输出结果时会改变a和b的值，之后a和b的值仍然是原来的值）。
 {
    int temp = a;
    a = b;
    b = temp;
 }
 
 void swap02(int *p1 , int *p2)//地址传递，会修改实参的值（永久改变a和b的值）。
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{


    int a = 10, b = 20;
    swap02(&a, &b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
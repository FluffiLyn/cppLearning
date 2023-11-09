#include <iostream>
using namespace std;
//1、const修饰指针：常量指针
//2、const修饰常量：指针常量
//3、const既修饰指针，又修饰常量：


int main()
{
    int a = 10, b = 10;
    
    const int * p1 = &a;//1、创建常量指针，指向a的地址
                       //特点：指针的指向可以修改，但是指针指向的值不可修改
    p1 = &b;           //不能写*p = 20，如果你想修改p1的值，应该写a=20

    int * const p2 =&a;//2、创建指针常量
    *p2 = 20;          //特点:指向不可以修改，但是指向的值可以通过*p2 = 20修改

    const int * const p3 = &a;//3、创建既修饰指针又修饰常量的玩意
                              //特点：既不可以修改指向也不可以修改指向的值
    cout << *p1 << endl << *p2 << endl << *p3 ;
    return 0;

}

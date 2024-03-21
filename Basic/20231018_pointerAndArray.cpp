#include <iostream>
using namespace std;
//利用指针访问数组中的元素


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "第一个元素为：" << arr[0] << endl;
    
    int * p = arr;//arr就是数组的首地址
    cout << "用指针访问第一个元素：" << *p << endl;
    
    p++;//让指针向后偏移四个字节（指针的自增自减与其它数据类型不一样）
    cout << "第二个：" << *p << endl;

    cout << "利用指针遍历数组：" << endl;
    int * p2 = arr;
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << *p2 << endl;
        p2++;
    }
    
    return 0;
}
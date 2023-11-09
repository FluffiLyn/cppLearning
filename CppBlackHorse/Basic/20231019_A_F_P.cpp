#include <iostream>
using namespace std;
//封装一个函数，利用冒泡排序，实现对整型数组的升序排序

//函数调用时，整型地址传递，需要加&表示取地址
//数组传递时默认为它的地址，因此不用添加&符

void bubbleSort(int * arr, int len)
{
    for(int i = 0; i < len - 1;i++)
    {
        for(int j = 0;j < len - i - 1;j++)
        {
            if(arr[j] > arr[j + 1])
            {    int temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int * arr, int len)
{
    for(int i = 0;i < len;i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[10] = {7,2,4,5,1,6,8,9,3,10} ;
    int len = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, len);
    printArray(arr, len);

    system("pause");
    return 0;
}
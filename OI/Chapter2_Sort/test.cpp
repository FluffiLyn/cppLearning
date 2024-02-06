#include <iostream>
using namespace std;

const int MAXN = 10001;

void insertSort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        //取出第二个元素
        //默认第一个元素是已排序的子列
        int temp = a[i];
        int j;

        //如果a[j]比temp值大，则后移一位
        //如果小，则说明temp应插入a[j]后一位
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int n, a[MAXN];

    cin >> n;
    for (int i = 0; i< n; i++)
    {
        cin >> a[i];
    }

    insertSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
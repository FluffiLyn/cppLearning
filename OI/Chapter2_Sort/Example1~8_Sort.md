# 排序

## 1. 选择排序
基本思想：每一趟从待排序的数据元素中选出最小（或最大）的一个元素，**顺序**放在待排序的数列的**最前**，直至全部元素排完。
```c++
#include <iostream>
using namespace std;

const int MAXN = 10001;

int main()
{
    int n,key;
    float temp, a[MAXN];
    
    cin >> n;
    //输入要排序的元素
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //i控制当前序列中最小值存放的数据位置
    for (int i = 0; i < n; i++)
    {
        key = i;
        //在当前无序区a[i, ... , n]中选择最小的元素a[key]
        for (int j = i + 1;j < n; j++)
        {
            if (a[j] < a[key])
            {
                key = j;
            }

            //交换
            if (key != i)
            {
                temp = a[i]; a[i] = a[key]; a[key] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
```

## 2. 冒泡排序
```c++
#include <iostream>
using namespace std;

const int MAXN = 10001;

int main()
{
    int n;
    bool flag;
    float temp, a[MAXN];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //进行n-1轮冒泡
    for (int i = n - 1; i >= 1; i--)
    {   
        flag = true;
        //每轮进行i次比较
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            flag = false;
        }
        if(flag) break;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
```

## 3. 插入排序
基本思想：通过构建有序序列，对于未排序数据，在已排序序列中**从后向前**扫描，找到相应位置并插入。类似打牌时摸牌并将其从大到小排列。每次摸到一张牌后，根据其点数插入到确切位置。

* 平均时间复杂度：O(N^2)
* 最差时间复杂度：O(N^2)
* 空间复杂度：O(1)
* 排序方式：In-place
* 稳定性：稳定

```c++
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
```
动图演示：

![动图演示](https://pic3.zhimg.com/v2-91b76e8e4dab9b0cad9a017d7dd431e2_b.webp "插入排序动图演示")

## 4. 桶排序
:thinking:

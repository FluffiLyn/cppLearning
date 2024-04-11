# 7. 分治算法
所谓分治，即"分而治之"，是将较大规模的问题分解成几个较小规模的问题。通过分别求解小规模问题，解决整体问题。

## 7.1 找数
给定一个长度为n的单调递增正整数序列，即序列中的每一个数都比前一个数大，有m个询问，每次询问一个x，问序列中最后一个小于等于x的数是什么。
\
\
输入：
```
第一行两个整数n，m。

接下来一行n个数，表示这个序列。

接下来m行每行一个数，表示一个询问。
```

输出：
```
输出m行，表示序列中最后一个小于等于x的数是什么。若没有则输出-1.
```

输入样例：
```
5 3
1 2 3 4 6
5
1
3
```
输出样例：
```
4
1
3
```

分析：
1. 用left表示左边界，right表示右边界，left=1,right=n。
2. 每次取平均值mid = (left+right)/2
3. 判断mid与x的关系：若a[mid]>x，则排除[mid, right]区间的所有数，并将右边界改为right=mid-1；若a[mid]<=x，则修改左边界left=mid+1
4. 重复这样的操作，直到left>right。循环结束时，left=right+1，此时right指向的是所求的值

```c++
#include <iostream>
using namespace std;

int n, m, a[1145],left_, right_;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    a[0] = -1;
    for (int i = 1; i <= m; i++)
    {
        left_ = 1, right_ = n;
        int x, mid;
        cin >> x;

        while (left_ <= right_)
        {
            mid = (left_ + right_) / 2;
            if (a[mid] > x) right_ = mid - 1; 
            else left_ = mid + 1;
        }
        cout << a[right_] << endl;
    }
    return 0;
}
```

## 7.2 取模运算
输入b、p、k的值，求b^p mod k的值，其中b，p，k*k为长整形数。

输入样例：
```
2 10 9
```
输出样例：
```
2^10 mod 9=7
```
# 6.  贪心算法
贪心算法（Greedy algorithm）是指在每一步选择中都做出局部最优的选择，从而希望得到全局最优解。

贪心算法不是对所有问题都能得到最优解，关键是贪心策略的选择。一般按照如下步骤进行：
1. 建立数学模型描述问题
2. 把求解的问题分成若干个子问题
3. 对每个子问题求解，得到子问题的局部最优解
4. 把局部最优解合并得到全局最优解

## 6.1 零钱找回问题
问题：假设1,2,5,10,20,50,100元的纸币分别有c0,c1,c2c3,c4,c5,c6,张，现在用这些钱支付K元，至少要用多少张纸币？

思路：每一步尽可能用面值大的纸币即可。

示例：
```c++
#include <iostream>
#include <math.h>
using namespace std;

int moneyType[7] = {1,2,5,10,20,50,100};
int moneyNum[7] = {2,5,1,3,4,0,4};

int cnt[7] = {0};//每种面值使用的张数
int total_count;

int greedy(int money)
{
    if (money >= 0)
    {
        for (int i = 6; i >= 0; i--)
        {
            //当前剩余金额除以当前面值面额可得所需当前面额的张数。
            //若所需当前面额张数小于剩余张数，则所需张数为当前面额张数，否则为剩余张数。
            cnt[i] = min(moneyNum[i], money / moneyType[i]);
            money = money - cnt[i] * moneyType[i];
        }
        return 0;
    }
    else
    {
        return money;
    }
}

int main()
{
    int money;
    cout << "请输入金额总数: ";
    cin >> money;

    if(money < 0)
    {
        cout << "Error!" << endl;

    }
    else
    {
        greedy(money);
        for (int j = 6; j>=0; j--)
        {
            cout<<moneyType[j]<<"元:"<<cnt[j]<<"张"<<endl;
        }


    }

    return 0;
}
```

## 6.2 均分纸牌
有n堆纸牌，编号分别为1，2，...，n。每堆有若干张，但纸牌总数必为n堆倍数。可以在任意堆上取若干纸牌，然后移动。

* 移牌规则为：在编号1上的堆上取的纸牌，只能移到编号2的堆上；在编号为n堆堆上取的纸牌，只能移到n-1堆上；其余纸牌可以任意移到相邻的堆上。

现在要找到一种方法，用最少移动次数使得每堆纸牌数一样多。

输入格式：n (1<=n<=100)
输出格式：最少移动次数

思想：求平均数，并将所有数减去平均数，将题目转化为"求使得所有牌堆变成0的最小步数"。
```c++
#include <iostream>
using namespace std;

int main()
{
    int n = 0, sum = 0,count = 0, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    //将所有数减去平均数，方便计算
    int j, k;
    sum /= n;
    for (j = 0; j < n; j++)
    {
        a[j] -= sum;
    }

    //过滤左右两边的0
    j = 0, k = n;
    while(a[j] == 0 && j < n) j++;
    while(a[k] == 0 && k > 0) k--;

    while(j < k)
    {
        a[j + 1] += a[j];
        a[j] = 0;
        count++; j++;
        //过滤移牌过程中产生的0
        while (a[j] == 0 && j < k) j++;
    }

    cout << count << endl;

    return 0;
}
```

## 6.3 删数问题
输入一个高精度整数n，去掉其中任意s个数字后，剩下的数字按原左右顺序组成新的正整数。寻找一个方案，使得剩下的数字组成的新数最小。

输入：n s
输出：剩下的最小数

思想：每一步总是选择一个使剩下的数最小的数字删去，即按**高位到低位**的顺序搜索。若各位数字递增，则删除最后一个数字，否则，删除第一个减区间的首个字符。回到串首，重复以上过程直至s次。

```c++
#include <iostream>
#include <string>
using namespace std;
int s, len;
string n;

int main()
{
    cin >> n >> s;
    len = n.length();

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (n[j] > n[j + 1])
            {
                //删除字符串n的下标为j+1的字符，后面的字符往前移动
                for (int k = j; k < len; k++)
                    n[k] = n[k + 1];
                n[len - 1] = '\0';
                len--;
                break;
            }
        }
    }

    //删除前导0
    for(int j = 0; n[j] == '0' && len > 1; j++)
    {
        len--;
    }

    cout << n << endl;

    return 0;
}
```
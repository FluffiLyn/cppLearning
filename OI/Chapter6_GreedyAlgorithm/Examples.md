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

## 6.2 活动安排问题

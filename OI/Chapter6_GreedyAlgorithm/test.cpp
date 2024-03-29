#include <iostream>
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
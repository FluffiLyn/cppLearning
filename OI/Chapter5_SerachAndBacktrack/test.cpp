#include <iostream>
#include <cmath>
using namespace std;

//将数组设为21个是想让数组下标能够对应数字1～20
bool b[21] = {0};//默认为false
int total = 0, a[21] = {0};

int search(int);
void printResult();
bool pd(int, int);//判断素数

int main()
{
    search(1);
    cout << total << endl;

    return 0;
}

int search(int t)
{
    int i = 1;
    for (i = 1; i <= 20; i++)//有20个数可选
    {
        if (pd(a[t - 1],i) && !(b[i]))//判断与前一个数是否构成素数并且该数字是否可用
        {
            a[t] = i;
            b[i] = true;
            if(t == 20)
            {
                if(pd(a[20],a[1])) printResult();
            }    
            else search(t + 1);
            b[i] = false;
        }
    }
}

void printResult()
{
    total++;
    cout << "<" << total << ">";
    for (int j = 1; j <= 20; j++)
        cout << a[j] << " ";
    cout << endl;
}

//判断两数之和是否为素数
bool pd(int x, int y)
{
    int k = 2,sum = x + y;
    while (k <= sqrt(sum) && sum % k != 0) k++;
    
    if (k > sqrt(sum)) return true;
    else return false;
}
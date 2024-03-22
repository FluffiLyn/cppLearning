#include <iostream>
using namespace std;


// 计算两个整数的最大公约数
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int num1, num2;
    cout << "请输入两个整数:";
    cin >> num1 >> num2;

    cout << "最小公倍数是：" << lcm(num1, num2) << endl;

    return 0;
}

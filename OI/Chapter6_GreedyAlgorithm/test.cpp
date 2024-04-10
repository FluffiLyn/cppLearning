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
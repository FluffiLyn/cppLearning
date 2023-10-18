#include <iostream>
using namespace std;

int main()
{
    int a;
    int flag = 1;
    
    cout << "Enter a number : " << endl;
    cin >> a;

    for (int i = 2;i < a - 1;i++)
    {
        if (a % i == 0)
        {
            cout << a << "不是素数" << endl;
            flag = 0;
            break;
        }
        else
            continue;
        
    }
    if (flag == 1)
        cout << a << "是素数" << endl;

    return 0;
}
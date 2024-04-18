#include <iostream>
using namespace std;
const int MAXN = 1025, MAXM = 11;
int matchlist[MAXN][MAXN];
int m;

int main()
{
    cout << "input:";
    cin >> m;
    int n = 1 << m, k = 0, half = 1;//左移运算符 
    matchlist[0][0] = 1;

    for (; k < m; k++)
    {   
        //通过左上方矩阵构造右上方矩阵
        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < half; j++)
                matchlist[i][j+half] = matchlist[i][j] + half;
        }
    
        //左上方=右下方，左下方=右上方
        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < half; j++)
            {
                matchlist[i + half][j] = matchlist[i][j + half];
                matchlist[i + half][j + half] = matchlist[i][j]; 
            }
        }
        half *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matchlist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

//此处的a[100][3]不是映射棋盘上所有位置的状态，而是记录搜索过程中马走过的路径信息
//a[i][1]是第i步时的横坐标
//a[i][2]是第i步时的纵坐标
//0被弃用
int a[100][3] = {0}, count;
//移动规则
int x[4] = {1,2,2,1};
int y[4] = {2,1,-1,-2};

void search(int);
void printResult(int);

int main()
{
    //将位置初始化，第一步在（0,0）处
    a[1][1] = 0; a[1][2] = 0;
    search(2);

    return 0;
}

void search(int i)
{
    for (int j = 0; j <= 3; j++)
    {
        //判断马是否越界
        if ((a[i-1][1] + y[j] >= 0) && (a[i-1][1] + y[j] <= 4)
        && (a[i-1][2] + x[j] >= 0) && (a[i-1][2] + x[j] <= 8))
        {
            //保存当前马的位置   
            a[i][1] = a[i-1][1] + y[j];          
            a[i][2] = a[i-1][2] + x[j];

            if (a[i][1] == 4 && a[i][2] == 8) printResult(i);
                else search(i+1);
        }   
    } 
}

void printResult(int input)
{
    count++;
    cout << count << ": ";
    for (int i = 1; i <= input - 1; i++)
    {
        cout << "(" << a[i][1] << "," << a[i][2] << ")" << "-->";
    }
    cout << "(4,8)" << endl;
}
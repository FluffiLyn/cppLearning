# 5. 搜索与回溯
基本框架一：
```c++
int search(int k)
{
   for (i = 0; i < num; i++)
   {
      if(true)
      {
         saveResult();
         if (ReachFinal()) printResult()
         else search(k + 1);
         Reset();//Or reverse()
      }
   }
}
```
基本框架二：
```c++
int search(int k)
{
    if (ReachFinal()) printResult();
    else
    {
        for (i = 0; i < num; i++)
        {
            if (true)
            {
                saveResult();
                search(k + 1);
                Reset();
            }
        }
    }
}
```

## 5.1 素数环
将1到20这20个数摆成一个环，要求相邻的两个数之和是一个素数。

算法流程：
1. 数据初始化
2. 递归填数，判断第i个数是否合法
   1. 若合法，则填数；判断是否填充完20个：若是，则打印结果，否则递归填下一个。
   2. 若不合法，则选择下一种可能

```c++
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
```

## 5.2 排列组合
设有n个整数的集合{1,2，...，n}，从中任意取出r个数进行排列（r < n），试列出所有的排列。
```c++
#include <iostream>
#include <cmath>
using namespace std;

int count = 0, a[114514] = {0}, n, r;
bool b[114514] = {0};
void search(int);
void printResult();

int main()
{
    cout << "Input n and r: ";
    cin >> n >> r;
    search(1);
    cout << "total = " << count << endl;
}

void search(int k)
{
    int i = 0;
    for (i; i < n; i++)
        if (!b[i])
        {
            a[k - 1] = i + 1;
            b[i] = true;
            if (k == r) printResult();
                else search(k + 1);
            b[i] = false;
        }   
}

void printResult()
{
    count++;
    for (int i = 0; i < r; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}
```
## 5.3 马的遍历
中国象棋的马自左下角往右上角跳，规定不允许左跳，只能右跳。求出所有的路线，并将所经的路线打印出来。打印格式为：0,0->2,1->...（棋盘横坐标为10，纵坐标为4）

分析：设原来的坐标为(x,y)，则四个方向的移动分别为
* (x,y)->(x+2,y+1)
* (x,y)->(x+1,y+2)
* (x,y)->(x+2,y-1)
* (x,y)->(x+2,y-2)

```c++
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
```

## 5.4 选书
学校放寒假时，信息学竞赛辅导老师有A，B，C，D，E五本书，要分给参加培训的张、王、刘、孙、李五位同学，每人只能选一本书。老师事先让每个人将自己喜欢的书填写在如下的表格中。然后根据他们填写的表来分配书本，希望设计一个程序帮助老师求出所有可能的分配方案，使每个学生都满意。
![图片](https://img-blog.csdnimg.cn/img_convert/782ad3e40d8dd9ff66da41a50e0ef40f.png) 

先用穷举法，求出五本书的所有全排列5!=120，然后在这里面删去不符合题意的解，剩余的即为题解。

```c++
#include <iostream>
#include <cmath>
using namespace std;

int book[6], count = 0;
bool flag[6], like[6][6] = {{0,0,0,0,0,0},{0,0,0,1,1,0},{0,1,1,0,0,1},
                                    {0,0,1,1,0,0},{0,0,0,0,1,0},{0,0,1,0,0,1}};
void search(int);
void printResult();

int main()
{
    for (int i = 1; i <= 5; i++)
        flag[i] = true;
    search(1);
}

void search(int i)
{
    for (int j = 1; j <= 5; j++)
    {
        if (flag[j] && like[i][j])
        {
            flag[j] = false;
            book[i] = j;
            if (i == 5) printResult();
                else search(i + 1); 
            flag[j] = true;
            book[i] = 0;
        }
    }    
}

void printResult()
{
    count++;
    cout << "Answer" << count << ":\n";
    for (int i = 1; i <= 5; i++)
    {
        cout << i << ": " << char(64+book[i]) << endl;
    }
}
```
输出：
```
Answer1:
1: C
2: A
3: B
4: D
5: E
```
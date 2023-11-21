/*
对于n（n>1）层汉诺塔，调用函数 move（n，A，B，C）来递归解决该问题，该函数执行的是
step1. 把除了最大的盘子之外的盘子从A移到B   move(n-1，A，C，B)         (借助C中转)
step2.  把最大的盘子从A移到C               cout('A--->C')
step3.  把除了最大的盘子之外的盘子从B移到C  move（n-1，B，A，C)  
*/


#include <iostream>
using namespace std;

void hanoi(int n, char from, char buffer, char to)
{
    if(n == 1)
        cout << from << "-->" << to << endl;
    else
    {
        hanoi(n - 1, from, to, buffer);//将前n-1个盘子移动到缓冲槽
        cout << from << "-->" << to << endl;
        hanoi(n - 1, buffer, from, to);//此时缓冲槽变成了原槽，原槽又作为新的缓冲槽，重复这个过程。（最后一个槽不用管了！）
    }
}

int main()
{
    int m;
    cout << "Input the number of diskes:" << endl;
    cin >> m;
    hanoi(m,'A','B','C');

    return 0;
}
/*
对于问题N，如果N-1已经解决了，那么N是否很容易解决。
举例来说，如果要把一个N层汉诺塔从A搬到C，那么：如果前N-1层可以找别人搞定，咱只管搬第N层，会不会变得非常容易？

你看，这一下就简单了：这时当它只有两层就好了，先把前N-1层看作一个整体，把它搬到B；然后把最下面的第N层搬到C；
然后再把前N-1层从B搬到C。类似的，假如接到“搬前N-1层”这个任务的是我们，怎么搬呢？

简单，像前东家一样，把前N-2层外包出去，我们只搬第N-1层——其实和前面讨论过的“外包N-1层，只搬第N层”完全一样嘛。
依此类推，一层层“外包”下去——我不管你们有多伤脑筋，反正只要你们把我外包给你的活干了，我就能干了我的活！
*/




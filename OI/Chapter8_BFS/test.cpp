#include <iostream>
#include <string>
using namespace std;

//1表示不可走，0表示可走
int ju[8][8]={{1,0,0,0,1,0,1,1},
             {0,1,1,0,0,1,1,1},
             {0,1,1,0,0,1,1,1},
             {0,1,0,1,1,1,0,1},
             {1,1,0,1,1,1,0,0},
             {0,0,1,1,1,1,1,0},
             {1,1,1,0,0,1,1,0},
             {1,1,1,1,0,0,0,1}};
int queue[101] = {0}, before[101] = {0};//queue时存储扩展节点的队列，记录经过的城市；before记录前趋城市 
bool s[8] = {0};//记录该城市已到过
void output(int d)
{
    cout << char(queue[d] + 64);
    while (before[d])
    {
        d = before[d];
        cout << "--" << char(queue[d] + 64);
    }
    cout << endl;
}

void bfs()
{
    int head = 0, tail = 1;
    queue[0] = 1; before[0] = 0; s[0] = 1;

    do
    {
        head++;
        for (int i = 0; i < 8; i++)
        {
            if (ju[queue[head]][i] == 0 && s[i] == 0)
            {
                tail++;
                queue[tail] = i;
                before[tail] = head;
                s[i] = 1;
                if (i == 7) 
                {
                    output(tail);
                    head = tail;
                    break;
                }
            }
        }
    }while(head < tail);
}

int main()
{
    bfs();

    return 0;
}
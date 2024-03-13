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
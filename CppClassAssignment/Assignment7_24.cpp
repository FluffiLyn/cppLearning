#include <iostream>
using namespace std;

bool isSafe(int row, int col, int board[][8])
{
    for (int i = 0; i < 8; i++)
    {
        if (board[i][col] == 1)
        return false;
    }
}

int main()
{

    return 0;
}
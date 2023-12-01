#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
int queens[N]; // 存放每个皇后所在的列数

int eliminationNumbers[N][N] = {
    {22, ,17 14, 11, 11, 14, 17, 22},
    {17, 12, 9, 6, 6, 9, 12, 17},
    {14, 9, 6, 3, 3, 6, 9, 14},
    {11, 6, 3, 0, 0, 3, 6, 11},
    {11, 6, 3, 0, 0, 3, 6, 11},
    {14, 9, 6, 3, 3, 6, 9, 14},
    {17, 12, 9, 6, 6, 9, 12, 17},
    {22, 17, 14, 11, 11, 14, 17, 22}
};

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i)
            return false;
    }
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        // 打印八皇后的解
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (queens[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    int minEliminationNumber = INT_MAX;
    vector<int> possibleColumns;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            if (eliminationNumbers[row][col] < minEliminationNumber)
            {
                minEliminationNumber = eliminationNumbers[row][col];
                possibleColumns.clear();
                possibleColumns.push_back(col);
            }
            else if (eliminationNumbers[row][col] == minEliminationNumber)
            {
                possibleColumns.push_back(col);
            }
        }
    }

    for (int col : possibleColumns)
    {
        queens[row] = col;
        solve(row + 1);
    }
}

int main()
{
    solve(0);
    return 0;
}

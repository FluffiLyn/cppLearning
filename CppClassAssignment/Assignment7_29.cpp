#include <iostream>
using namespace std;

//Number 1 means there is a queen.
bool isSafe(int row, int col, int board[][8])
{
    //To check the row
    for (int i = 0; i < 8; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    //To check the anti-diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    //To check the main diagonal
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool eightQueens(int board[][8], int currentRow)
{
    //The end of this function
    if (currentRow == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j< 8; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
       
        return true;
    }

    //NOTICE: Following are the most important part of eightQueens()
    bool res = false;
    for (int col = 0; col < 8; col++)
    {
        if(isSafe(currentRow, col, board))
        {
            board[currentRow][col] = 1;

            //If a solution is found, then res = true.
            //If not, res remains the last status.
            //Put next queen in the next row by recursion.
            res = eightQueens(board, currentRow + 1) || res;

            board[currentRow][col] = 0;
        }
    }

    return res;
}

int main()
{
    int chessBoard[8][8] = {0};

    eightQueens(chessBoard, 0);//Start from row 0

    return 0;
}

/*
当我们尝试放置一个皇后时，我们并不知道这个选择是否会导致最终的解。因此，我们需要尝试所有可能的选择。
    
当我们将皇后放置在一个位置上时（例如 board[row][col]=1），我们会递归调用解决下一行的皇后问题。如果这个选择最终导致了无法找到解，
    那么我们就需要取消这个选择，尝试其他的可能性。这就是为什么在递归调用之后会有一个回溯的过程，将之前放置的皇后移除（即 board[row][col]=0）。
    
通过不断地尝试放置和回溯，算法能够搜索所有可能的解空间，最终找到所有的解。这种回溯的思想是解决许多组合优化问题的常用方法，它能够确保所有可能的情况都被考虑到，从而找到最优解或者所有解。
*/
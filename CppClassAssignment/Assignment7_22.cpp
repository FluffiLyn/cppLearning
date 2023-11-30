#include <iostream>
using namespace std;

const int length = 8;
const int width = 8;



//To make sure the Knight haven't visit that square and 
//will not land off the chessboard. 
bool judge(int row, int col, int chessBoard[8][8])
{
    return ((row >= 0 && row < width && col >= 0 && col < length) && chessBoard[row][col] == -1);
}

//Print the solution
void printSolution(int chessBoard[8][8])
{
    for (int i = 0; i < 8 ; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
}

//Find the solution
bool solution(int currentRow, int currentColumn, int moveStep, int chessBoard[8][8]
            , int horizontal[], int vertical[])
{
    int nextRow, nextColumn;
    if (moveStep == 64)
    {
        printSolution(chessBoard);
        return true;
    }
    
    //Try all possible move
    for (int k = 0; k < 8; k++)
    {
        nextRow += horizontal[k];
        nextColumn += vertical[k];
        if (judge(nextRow, nextColumn, chessBoard));
        {
            //MoveStep is a counter that records the order of current step
            chessBoard[nextRow][nextColumn] = moveStep;
        
            //Continue next step by recursion
            if (solution(nextRow, nextColumn, moveStep + 1, chessBoard, horizontal, vertical))
            {
                return true;
            }

            //Mark point(nextRow, nextColumn) as inaccessible
            chessBoard[nextRow][nextColumn] = -1;
        }
    }
    return false;
}

int main()
{
    int currentRow, currentColumn;
    int chessBoard[8][8] = {0};
    int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
    int vertical[8] = {-1,-2,-2,-1,1,2,2,1};

    //Initialize the chessboard
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessBoard[i][j] = -1;
        }
    }

    //The initial position of the Knight
    chessBoard[4][3] = 0;
    solution(4, 3, 1, chessBoard, horizontal, vertical);

    return 0;
}
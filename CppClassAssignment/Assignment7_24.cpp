#include <iostream>
using namespace std;

const int boardSize = 8;
int elimination_numbers[boardSize][boardSize] = 
{
    {22, 11, 11, 11, 11, 11, 11, 22},
    {11, 22, 11, 11, 11, 11, 22, 11},
    {11, 11, 22, 11, 11, 22, 11, 11},
    {11, 11, 11, 22, 22, 11, 11, 11},
    {11, 11, 11, 22, 22, 11, 11, 11},
    {11, 11, 22, 11, 11, 22, 11, 11},
    {11, 22, 11, 11, 11, 11, 22, 11},
    {22, 11, 11, 11, 11, 11, 11, 22}
};

bool isSafe(int row, int col, int position[]) 
{
    for (int i = 0; i < row; i++) 
    {
        if (position[i] == col || position[i] - col == i - row || position[i] - col == row - i) 
        {
            return false;
        }
    }
    return true;
}

void solve(int row, int position[], int& totalElimination) 
{
    if (row == boardSize) 
    {
        //Print the result
        for (int i = 0; i < boardSize; i++) 
        {
            for (int j = 0; j < boardSize; j++) 
            {
                if (position[i] == j) 
                {
                    cout << "1 ";
                } 
                else 
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < boardSize; col++) 
    {
        if (isSafe(row, col, position)) 
        {
            // Put queen at current position
            position[row] = col;
            totalElimination += elimination_numbers[row][col];
            //Solve the next row
            solve(row + 1, position, totalElimination);
            
            totalElimination -= elimination_numbers[row][col]; 
        }
    }
}

int main() 
{
    int position[boardSize] = {0};//The position of the queen is (index, value)
    int totalElimination = 0;
    solve(0, position, totalElimination);
    return 0;
}

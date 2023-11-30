#include <iostream>

#define N 8

// 验证下一步是否在棋盘内且未访问过
bool isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// 打印最终路径
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// 回溯算法求解骑士巡游问题
bool solveKnightTour(int x, int y, int movei, int board[N][N],
                     int xMove[], int yMove[]) {
    int nextX, nextY;
    if (movei == N * N) {
        // 已经访问了全部的单元格，找到了一条可行路径
        printSolution(board);
        return true;
    }

    // 尝试所有可能的移动方式
    for (int k = 0; k < 8; ++k) {
        nextX = x + xMove[k];
        nextY = y + yMove[k];
        if (isSafe(nextX, nextY, board)) {
            // 标记当前单元格已访问
            board[nextX][nextY] = movei;
            // 递归地继续探索下一步
            if (solveKnightTour(nextX, nextY, movei + 1, board, xMove, yMove))
                return true;
            // 回溯，取消当前单元格的访问标记
            board[nextX][nextY] = -1;
        }
    }
    return false;
}

int main() {
    int board[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = -1;
        }
    }

    // 骑士可以按照以下顺序移动
    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // 从起始位置开始搜索可行路径
    board[0][0] = 0; // 起始位置标记为已访问
    solveKnightTour(0, 0, 1, board, xMove, yMove);

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 函数用于在矩阵中查找目标数字
int searchMatrix(int matrix[][3], int target, int rows, int columns) {
    int row = 0;
    int col = columns - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return 1;  // 目标数字存在于矩阵中
        }
        else if (matrix[row][col] > target) {
            col--;  // 当前数字比目标数字大，向左移动一列
        }
        else {
            row++;  // 当前数字比目标数字小，向下移动一行
        }
    }

    return 0;  // 目标数字不存在于矩阵中
}

int main() {
    int matrix[3][3] = { {1, 3, 5},
                        {7, 9, 11},
                        {13, 15, 17} };
    int target = 9;
    int rows = 3;
    int columns = 3;

    int result = searchMatrix(matrix, target, rows, columns);

    if (result) {
        printf("目标数字存在于矩阵中。\n");
    }
    else {
        printf("目标数字不存在于矩阵中。\n");
    }

    return 0;
}
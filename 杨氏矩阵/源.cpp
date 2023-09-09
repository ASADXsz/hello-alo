#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ���������ھ����в���Ŀ������
int searchMatrix(int matrix[][3], int target, int rows, int columns) {
    int row = 0;
    int col = columns - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return 1;  // Ŀ�����ִ����ھ�����
        }
        else if (matrix[row][col] > target) {
            col--;  // ��ǰ���ֱ�Ŀ�����ִ������ƶ�һ��
        }
        else {
            row++;  // ��ǰ���ֱ�Ŀ������С�������ƶ�һ��
        }
    }

    return 0;  // Ŀ�����ֲ������ھ�����
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
        printf("Ŀ�����ִ����ھ����С�\n");
    }
    else {
        printf("Ŀ�����ֲ������ھ����С�\n");
    }

    return 0;
}
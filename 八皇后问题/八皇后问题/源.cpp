#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10
int count = 0;
// 定义栈结构
typedef struct Stack {
    int data[MAX_N];
    int top; // 栈顶指针，指向最后一个有效元素的下标
} Stack;

// 初始化栈
void initStack(Stack* stk) {
    stk->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack* stk) {
    return stk->top == -1;
}

// 判断栈是否已满
bool isFull(Stack* stk, int N) {
    return stk->top == N - 1;
}

// 将元素入栈
bool push(Stack* stk, int x, int N) {
    if (isFull(stk, N))
        return false;
    stk->data[++(stk->top)] = x;
    return true;
}

// 弹出栈顶元素
bool pop(Stack* stk) {
    if (isEmpty(stk))
        return false;
    --(stk->top);
    return true;
}

// 获取栈顶元素
int top(Stack* stk) {
    return stk->data[stk->top];
}

// 打印棋盘布局
void printSolution(Stack* stk, int N) {
    printf("第%d种解决方案:\n", ++count); // 每次调用该函数都会统计方案数并输出当前方案编号
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (stk->data[i] == j)
                printf("1 ");
            else
                printf("0 ");
        printf("\n");
    }
    printf("\n");
}

// 判断当前皇后是否与已有皇后的位置冲突
bool isSafe(Stack* stk, int row, int col) {
    for (int i = 0; i < row; i++) {
        int col_i = stk->data[i]; // 第 i 行皇后所在的列号
        // 检查是否在同一列或同一条对角线上
        if (col_i == col || abs(row - i) == abs(col - col_i))
            return false;
    }
    return true;
}

// 递归求解 N 皇后问题
void solveNQueensUtil(Stack* stk, int row, int N) {
    // 如果已经找到一种解决方案，打印出棋盘布局并返回
    if (row == N) {
        printSolution(stk, N);
        return;
    }

    // 在当前行依次枚举每个位置
    for (int col = 0; col < N; col++) {
        // 判断是否与已有皇后的位置冲突
        if (isSafe(stk, row, col)) {
            push(stk, col, N); // 如果当前位置合法，将皇后放在这里
            solveNQueensUtil(stk, row + 1, N); // 继续向下一行寻找合适的解决方案
            pop(stk); // 回溯到当前行，撤销操作
        }
    }
}

// 求解 N 皇后问题的解
void solveNQueens(int N) {
    Stack stk;
    initStack(&stk); // 初始化栈
    push(&stk, -1, N); // 先将第 0 行的皇后位置（列号）入栈
    while (!isEmpty(&stk)) {
        int col = top(&stk);
        pop(&stk);
        // 针对当前行枚举每个位置，判断是否符合要求，如果符合就入栈
        col++;
        while (col < N) {
            if (isSafe(&stk, stk.top + 1, col)) {
                push(&stk, col, N);
                col = -1; // 进入下一行，从第一个位置开始枚举
                break;
            }
            col++;
        }
        if (col == N) // 当前行没有找到合适的位置，回溯到上一行
            continue;
        if (stk.top == N - 1) // 找到一种解决方案，打印出棋盘布局
            printSolution(&stk, N);
        push(&stk, -1, N); // 先将下一行皇后位置（列号）入栈
    }
}

int main() {
    int N;
    printf("请输入 N 的值（1 <= N <= 10）: ");
    scanf("%d", &N);
    solveNQueens(N);
    printf("一共有%d种方案", count);
    return 0;
}

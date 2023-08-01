#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10
int count = 0;
// ����ջ�ṹ
typedef struct Stack {
    int data[MAX_N];
    int top; // ջ��ָ�룬ָ�����һ����ЧԪ�ص��±�
} Stack;

// ��ʼ��ջ
void initStack(Stack* stk) {
    stk->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack* stk) {
    return stk->top == -1;
}

// �ж�ջ�Ƿ�����
bool isFull(Stack* stk, int N) {
    return stk->top == N - 1;
}

// ��Ԫ����ջ
bool push(Stack* stk, int x, int N) {
    if (isFull(stk, N))
        return false;
    stk->data[++(stk->top)] = x;
    return true;
}

// ����ջ��Ԫ��
bool pop(Stack* stk) {
    if (isEmpty(stk))
        return false;
    --(stk->top);
    return true;
}

// ��ȡջ��Ԫ��
int top(Stack* stk) {
    return stk->data[stk->top];
}

// ��ӡ���̲���
void printSolution(Stack* stk, int N) {
    printf("��%d�ֽ������:\n", ++count); // ÿ�ε��øú�������ͳ�Ʒ������������ǰ�������
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

// �жϵ�ǰ�ʺ��Ƿ������лʺ��λ�ó�ͻ
bool isSafe(Stack* stk, int row, int col) {
    for (int i = 0; i < row; i++) {
        int col_i = stk->data[i]; // �� i �лʺ����ڵ��к�
        // ����Ƿ���ͬһ�л�ͬһ���Խ�����
        if (col_i == col || abs(row - i) == abs(col - col_i))
            return false;
    }
    return true;
}

// �ݹ���� N �ʺ�����
void solveNQueensUtil(Stack* stk, int row, int N) {
    // ����Ѿ��ҵ�һ�ֽ����������ӡ�����̲��ֲ�����
    if (row == N) {
        printSolution(stk, N);
        return;
    }

    // �ڵ�ǰ������ö��ÿ��λ��
    for (int col = 0; col < N; col++) {
        // �ж��Ƿ������лʺ��λ�ó�ͻ
        if (isSafe(stk, row, col)) {
            push(stk, col, N); // �����ǰλ�úϷ������ʺ��������
            solveNQueensUtil(stk, row + 1, N); // ��������һ��Ѱ�Һ��ʵĽ������
            pop(stk); // ���ݵ���ǰ�У���������
        }
    }
}

// ��� N �ʺ�����Ľ�
void solveNQueens(int N) {
    Stack stk;
    initStack(&stk); // ��ʼ��ջ
    push(&stk, -1, N); // �Ƚ��� 0 �еĻʺ�λ�ã��кţ���ջ
    while (!isEmpty(&stk)) {
        int col = top(&stk);
        pop(&stk);
        // ��Ե�ǰ��ö��ÿ��λ�ã��ж��Ƿ����Ҫ��������Ͼ���ջ
        col++;
        while (col < N) {
            if (isSafe(&stk, stk.top + 1, col)) {
                push(&stk, col, N);
                col = -1; // ������һ�У��ӵ�һ��λ�ÿ�ʼö��
                break;
            }
            col++;
        }
        if (col == N) // ��ǰ��û���ҵ����ʵ�λ�ã����ݵ���һ��
            continue;
        if (stk.top == N - 1) // �ҵ�һ�ֽ����������ӡ�����̲���
            printSolution(&stk, N);
        push(&stk, -1, N); // �Ƚ���һ�лʺ�λ�ã��кţ���ջ
    }
}

int main() {
    int N;
    printf("������ N ��ֵ��1 <= N <= 10��: ");
    scanf("%d", &N);
    solveNQueens(N);
    printf("һ����%d�ַ���", count);
    return 0;
}

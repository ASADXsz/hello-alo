#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAXSIZE 100
int maze[MAXSIZE][MAXSIZE]; // �Թ�����
int visit[MAXSIZE][MAXSIZE]; // ��Ǿ���
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // �ĸ�����
// ����ջ�ڵ�ṹ��
struct StackNode {
    int x, y;
};
// ����ջ�ṹ��
struct Stack {
    struct StackNode data[MAXSIZE * MAXSIZE];
    int top;
};
// ��ʼ��ջ
void InitStack(struct Stack* pStack) {
    pStack->top = -1;
}
// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(struct Stack* pStack) {
    return pStack->top == -1;
}
// ��Ԫ����ջ
void Push(struct Stack* pStack, int x, int y) {
    if ((pStack->top) + 1 < MAXSIZE * MAXSIZE) {
        struct StackNode node = { x, y };
        pStack->data[++(pStack->top)] = node;
    }
}
// ��Ԫ�س�ջ������
struct StackNode Pop(struct Stack* pStack) {
    struct StackNode node = { -1, -1 };
    if (pStack->top >= 0) {
        node = pStack->data[pStack->top--];
    }
    return node;
}

// ��ȡջ��Ԫ��
struct StackNode Top(struct Stack* pStack) {
    struct StackNode node = { -1, -1 };
    if (pStack->top >= 0) {
        node = pStack->data[pStack->top];
    }
    return node;
}

// ��������
void Backtrack(int cur_x, int cur_y, int end_x, int end_y, int m, int n, struct Stack* pStack, int* flag) {
    if (cur_x == end_x && cur_y == end_y) {
        // �����յ㣬���·��
        for (int i = 0; i <= pStack->top; i++) {
            printf("(%d,%d)", pStack->data[i].x, pStack->data[i].y);
        }
        printf("\n");
        *flag = 1; // �ҵ�·��������־��Ϊ 1
    }
    else {
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + direction[i][0];
            int next_y = cur_y + direction[i][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && maze[next_x][next_y] == 0 && visit[next_x][next_y] == 0) {
                // ��ǵ�ǰ�ڵ��ѷ��ʣ�����ջ
                visit[next_x][next_y] = 1;
                Push(pStack, next_x, next_y);
                // ������������������
                Backtrack(next_x, next_y, end_x, end_y, m, n, pStack, flag);
                // ����Ѿ��ҵ�·��������Ҫ�ټ���������
                if (*flag == 1) {
                    return;
                }
                // ȡ����ǲ���ջ
                visit[next_x][next_y] = 0;
                Pop(pStack);
            }
        }
    }
}
int main() {
    int m, n;
    printf("�������Թ��Ĵ�С������ ��������");
    scanf("%d %d", &m, &n);
    // �����Թ�����
    printf("�������Թ��ľ���0 ��ʾͨ·��1 ��ʾ�ϰ�����\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            visit[i][j] = 0; // ��ʼ����Ǿ���
        }
    }
    printf("���Թ���·��Ϊ��\n");
    struct Stack stack;
    InitStack(&stack);
    Push(&stack, 0, 0);
    visit[0][0] = 1;
    int flag = 0;
    Backtrack(0, 0, m - 1, n - 1, m, n, &stack, &flag);
    if (flag == 0) {
        printf("û�п���·����\n");
    }
    printf("�����ѽ�����\n");
    return 0;
}


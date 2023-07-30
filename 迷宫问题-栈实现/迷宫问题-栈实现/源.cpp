#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAXSIZE 100
int maze[MAXSIZE][MAXSIZE]; // 迷宫矩阵
int visit[MAXSIZE][MAXSIZE]; // 标记矩阵
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 四个方向
// 定义栈节点结构体
struct StackNode {
    int x, y;
};
// 定义栈结构体
struct Stack {
    struct StackNode data[MAXSIZE * MAXSIZE];
    int top;
};
// 初始化栈
void InitStack(struct Stack* pStack) {
    pStack->top = -1;
}
// 判断栈是否为空
int IsEmpty(struct Stack* pStack) {
    return pStack->top == -1;
}
// 将元素入栈
void Push(struct Stack* pStack, int x, int y) {
    if ((pStack->top) + 1 < MAXSIZE * MAXSIZE) {
        struct StackNode node = { x, y };
        pStack->data[++(pStack->top)] = node;
    }
}
// 将元素出栈并返回
struct StackNode Pop(struct Stack* pStack) {
    struct StackNode node = { -1, -1 };
    if (pStack->top >= 0) {
        node = pStack->data[pStack->top--];
    }
    return node;
}

// 获取栈顶元素
struct StackNode Top(struct Stack* pStack) {
    struct StackNode node = { -1, -1 };
    if (pStack->top >= 0) {
        node = pStack->data[pStack->top];
    }
    return node;
}

// 回溯搜索
void Backtrack(int cur_x, int cur_y, int end_x, int end_y, int m, int n, struct Stack* pStack, int* flag) {
    if (cur_x == end_x && cur_y == end_y) {
        // 到达终点，输出路径
        for (int i = 0; i <= pStack->top; i++) {
            printf("(%d,%d)", pStack->data[i].x, pStack->data[i].y);
        }
        printf("\n");
        *flag = 1; // 找到路径，将标志设为 1
    }
    else {
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + direction[i][0];
            int next_y = cur_y + direction[i][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && maze[next_x][next_y] == 0 && visit[next_x][next_y] == 0) {
                // 标记当前节点已访问，并入栈
                visit[next_x][next_y] = 1;
                Push(pStack, next_x, next_y);
                // 沿着这个方向继续搜索
                Backtrack(next_x, next_y, end_x, end_y, m, n, pStack, flag);
                // 如果已经找到路径，则不需要再继续搜索了
                if (*flag == 1) {
                    return;
                }
                // 取消标记并出栈
                visit[next_x][next_y] = 0;
                Pop(pStack);
            }
        }
    }
}
int main() {
    int m, n;
    printf("请输入迷宫的大小（行数 列数）：");
    scanf("%d %d", &m, &n);
    // 输入迷宫矩阵
    printf("请输入迷宫的矩阵（0 表示通路，1 表示障碍）：\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            visit[i][j] = 0; // 初始化标记矩阵
        }
    }
    printf("出迷宫的路径为：\n");
    struct Stack stack;
    InitStack(&stack);
    Push(&stack, 0, 0);
    visit[0][0] = 1;
    int flag = 0;
    Backtrack(0, 0, m - 1, n - 1, m, n, &stack, &flag);
    if (flag == 0) {
        printf("没有可行路径！\n");
    }
    printf("程序已结束。\n");
    return 0;
}


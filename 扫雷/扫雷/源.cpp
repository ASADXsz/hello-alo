#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>

// 扫雷中级模式
#define SIZE 40 // 每个格子的大小
#define ROW 16 // 行数
#define COL 16 // 列数
#define NUM 40 // 雷数

int count; // 已经翻开的格子数量
IMAGE img[12]; // 存放图片的数组
int map[ROW + 2][COL + 2]; // 存放雷和数字的地图数组，为了方便计算和判断，多出两行两列

// 游戏初始化函数
void gameinit() {
    srand((unsigned int)time(NULL)); // 用当前时间作为随机数生成器的种子，避免每次运行结果相同

    // 初始化地图数组，雷和数字都为0
    for (int i = 0; i < ROW + 2; i++)
    {
        for (int j = 0; j < COL + 2; j++)
        {
            map[i][j] = 0;
        }
    }

    int n = 0;
    // 随机生成NUM个雷
    while (n < NUM)
    {
        int r = rand() % ROW;
        int c = rand() % COL;
        if (map[r][c] == 0)
        {
            map[r][c] = -1; // 用-1表示这个位置是雷
            n++;
        }
    }

    // 计算每个非雷格子周围的雷数
    for (int i = 1; i <= ROW + 1; i++)
    {
        for (int j = 1; j < COL + 1; j++)
        {
            if (map[i][j] != -1)
            {
                for (int m = i - 1; m <= i + 1; m++)
                {
                    for (int n = j - 1; n <= j + 1; n++)
                    {
                        if (map[m][n] == -1)
                        {
                            map[i][j]++; // 在这个格子周围的雷数加1
                            n++; // 避免重复计算
                        }
                    }
                }
            }
        }
    }

    // 将雷和数字的值都加上20，方便后面显示图片
    for (int i = 1; i < ROW + 1; i++) {
        for (int j = 1; j < COL + 1; j++) {
            map[i][j] += 20;
        }
    }
}

// 绘制游戏界面
void gamedraw() {
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COL; j++)
        {
            // 根据不同的值显示不同的图片
            if (map[i][j] == -1) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[9]); // 显示雷的图片
            }
            else if (map[i][j] >= 0 && map[i][j] <= 8) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[map[i][j]]); // 显示数字对应的图片
            }
            else if (map[i][j] >= 19 && map[i][j] <= 28) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[10]); // 显示未翻开的格子的图片
            }
            else if (map[i][j] > 30) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[11]); // 显示标记的图片
            }
        }
        printf("\n");
    }
}

// 递归翻开周围所有的空白格子
void openzero(int r, int c) {
    map[r][c] -= 20; // 翻开这个格子
    count++; // 翻开的格子数量加1
    for (int m = r - 1; m <= r + 1; m++) {
        for (int n = c - 1; n <= c + 1; n++) {
            if (m >= 1 && m <= ROW && n >= 1 && n <= COL) { // 如果这个格子在地图范围内
                if (map[m][n] >= 19 && map[m][n] <= 28) { // 如果这个格子未翻开
                    if (map[m][n] != 20) {
                        map[m][n] -= 20; // 翻开这个格子
                        count++; // 翻开的格子数量加1
                    }
                    else {
                        openzero(m, n); // 如果是空白格子，递归翻开周围所有的空白格子
                    }
                }
            }
        }
    }
}

// 翻开一个格子，并返回格子的值
int Playgame() {
    MOUSEMSG msg = { 0 };
    int r, c;
    while (1) {
        msg = GetMouseMsg();
        switch (msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            r = msg.x / SIZE + 1; // 计算鼠标点击的位置对应的行列坐标
            c = msg.y / SIZE + 1;
            if (map[r][c] >= 19 && map[r][c] <= 28) { // 如果这个格子未翻开
                if (map[r][c] == 20) {
                    openzero(r, c); // 如果是空白格子，递归翻开周围所有的空白格子
                }
                else {
                    map[r][c] -= 20; // 如果是数字格子，翻开这个格子
                    count++; // 翻开的格子数量加1
                }
            }
            return map[r][c];
            break;
        case WM_RBUTTONDOWN:
            r = msg.x / SIZE + 1;
            c = msg.y / SIZE + 1;
            if (map[r][c] >= 19 && map[r][c] <= 28) { 
                if (map[r][c] > 30) {
                    map[r][c] -= 50; // 取消标记
                }
                else {
                    map[r][c] += 50; // 标记这个格子为雷
                }
            }
            return map[r][c]; 
            break;
        }
    }
}

int main() {
    HWND hwnd = initgraph(SIZE * ROW, SIZE * COL, SHOWCONSOLE); // 初始化图形界面
    loadimage(&img[0], "0.jpg", SIZE, SIZE); // 加载图片
    loadimage(&img[1], "1.jpg", SIZE, SIZE);
    loadimage(&img[2], "2.jpg", SIZE, SIZE);
    loadimage(&img[3], "3.jpg", SIZE, SIZE);
    loadimage(&img[4], "4.jpg", SIZE, SIZE);
    loadimage(&img[5], "5.jpg", SIZE, SIZE);
    loadimage(&img[6], "6.jpg", SIZE, SIZE);
    loadimage(&img[7], "7.jpg", SIZE, SIZE);
    loadimage(&img[8], "8.jpg", SIZE, SIZE);
    loadimage(&img[9], "9.jpg", SIZE, SIZE);
    loadimage(&img[10], "10.jpg", SIZE, SIZE);
    loadimage(&img[11], "11.jpg", SIZE, SIZE);
    gameinit(); // 初始化游戏
    while (1) {
        gamedraw(); // 绘制游戏界面
        if (Playgame() == -1) { // 如果翻开的格子是雷
            gamedraw(); // 再次绘制游戏界面，显示所有的雷
            MessageBox(hwnd, "你输了", "", MB_OK); 
            break; // 结束游戏
        }
        if (ROW * COL - NUM == count) { // 如果所有的非雷格子都被翻开了
            gamedraw(); // 再次绘制游戏界面，显示所有的数字
            MessageBox(hwnd, "恭喜你，你赢了!", "", MB_OK); 
            break;
        }
    }
    return 0;
}

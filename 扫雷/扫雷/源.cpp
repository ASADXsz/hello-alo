#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>

// ɨ���м�ģʽ
#define SIZE 40 // ÿ�����ӵĴ�С
#define ROW 16 // ����
#define COL 16 // ����
#define NUM 40 // ����

int count; // �Ѿ������ĸ�������
IMAGE img[12]; // ���ͼƬ������
int map[ROW + 2][COL + 2]; // ����׺����ֵĵ�ͼ���飬Ϊ�˷��������жϣ������������

// ��Ϸ��ʼ������
void gameinit() {
    srand((unsigned int)time(NULL)); // �õ�ǰʱ����Ϊ����������������ӣ�����ÿ�����н����ͬ

    // ��ʼ����ͼ���飬�׺����ֶ�Ϊ0
    for (int i = 0; i < ROW + 2; i++)
    {
        for (int j = 0; j < COL + 2; j++)
        {
            map[i][j] = 0;
        }
    }

    int n = 0;
    // �������NUM����
    while (n < NUM)
    {
        int r = rand() % ROW;
        int c = rand() % COL;
        if (map[r][c] == 0)
        {
            map[r][c] = -1; // ��-1��ʾ���λ������
            n++;
        }
    }

    // ����ÿ�����׸�����Χ������
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
                            map[i][j]++; // �����������Χ��������1
                            n++; // �����ظ�����
                        }
                    }
                }
            }
        }
    }

    // ���׺����ֵ�ֵ������20�����������ʾͼƬ
    for (int i = 1; i < ROW + 1; i++) {
        for (int j = 1; j < COL + 1; j++) {
            map[i][j] += 20;
        }
    }
}

// ������Ϸ����
void gamedraw() {
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COL; j++)
        {
            // ���ݲ�ͬ��ֵ��ʾ��ͬ��ͼƬ
            if (map[i][j] == -1) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[9]); // ��ʾ�׵�ͼƬ
            }
            else if (map[i][j] >= 0 && map[i][j] <= 8) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[map[i][j]]); // ��ʾ���ֶ�Ӧ��ͼƬ
            }
            else if (map[i][j] >= 19 && map[i][j] <= 28) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[10]); // ��ʾδ�����ĸ��ӵ�ͼƬ
            }
            else if (map[i][j] > 30) {
                putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[11]); // ��ʾ��ǵ�ͼƬ
            }
        }
        printf("\n");
    }
}

// �ݹ鷭����Χ���еĿհ׸���
void openzero(int r, int c) {
    map[r][c] -= 20; // �����������
    count++; // �����ĸ���������1
    for (int m = r - 1; m <= r + 1; m++) {
        for (int n = c - 1; n <= c + 1; n++) {
            if (m >= 1 && m <= ROW && n >= 1 && n <= COL) { // �����������ڵ�ͼ��Χ��
                if (map[m][n] >= 19 && map[m][n] <= 28) { // ����������δ����
                    if (map[m][n] != 20) {
                        map[m][n] -= 20; // �����������
                        count++; // �����ĸ���������1
                    }
                    else {
                        openzero(m, n); // ����ǿհ׸��ӣ��ݹ鷭����Χ���еĿհ׸���
                    }
                }
            }
        }
    }
}

// ����һ�����ӣ������ظ��ӵ�ֵ
int Playgame() {
    MOUSEMSG msg = { 0 };
    int r, c;
    while (1) {
        msg = GetMouseMsg();
        switch (msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            r = msg.x / SIZE + 1; // �����������λ�ö�Ӧ����������
            c = msg.y / SIZE + 1;
            if (map[r][c] >= 19 && map[r][c] <= 28) { // ����������δ����
                if (map[r][c] == 20) {
                    openzero(r, c); // ����ǿհ׸��ӣ��ݹ鷭����Χ���еĿհ׸���
                }
                else {
                    map[r][c] -= 20; // ��������ָ��ӣ������������
                    count++; // �����ĸ���������1
                }
            }
            return map[r][c];
            break;
        case WM_RBUTTONDOWN:
            r = msg.x / SIZE + 1;
            c = msg.y / SIZE + 1;
            if (map[r][c] >= 19 && map[r][c] <= 28) { 
                if (map[r][c] > 30) {
                    map[r][c] -= 50; // ȡ�����
                }
                else {
                    map[r][c] += 50; // ����������Ϊ��
                }
            }
            return map[r][c]; 
            break;
        }
    }
}

int main() {
    HWND hwnd = initgraph(SIZE * ROW, SIZE * COL, SHOWCONSOLE); // ��ʼ��ͼ�ν���
    loadimage(&img[0], "0.jpg", SIZE, SIZE); // ����ͼƬ
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
    gameinit(); // ��ʼ����Ϸ
    while (1) {
        gamedraw(); // ������Ϸ����
        if (Playgame() == -1) { // ��������ĸ�������
            gamedraw(); // �ٴλ�����Ϸ���棬��ʾ���е���
            MessageBox(hwnd, "������", "", MB_OK); 
            break; // ������Ϸ
        }
        if (ROW * COL - NUM == count) { // ������еķ��׸��Ӷ���������
            gamedraw(); // �ٴλ�����Ϸ���棬��ʾ���е�����
            MessageBox(hwnd, "��ϲ�㣬��Ӯ��!", "", MB_OK); 
            break;
        }
    }
    return 0;
}

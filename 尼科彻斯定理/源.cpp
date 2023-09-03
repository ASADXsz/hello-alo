#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cubeSum(int m) {
    int start = m * m - (m - 1);  // 连续奇数的起始值
    int sum = 0;
    int i;


    // 输出连续奇数之和
    for (i = 0; i < m; i++) {
        printf("%d", start + 2 * i);
        sum += start + 2 * i;

        if (i < m - 1) {
            printf("+");
        }
    }

    printf("\n");
}

int main() {
    int m;
    scanf("%d", &m);

    cubeSum(m);

    return 0;
}
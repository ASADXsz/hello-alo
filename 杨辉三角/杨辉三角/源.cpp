#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n, i, j, coef = 1;
    printf("请输入要打印的杨辉三角的行数：");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1;
            }
            else {
                coef = coef * (i - j + 1) / j;
            }
            printf("%d ", coef);
        }
        printf("\n");
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int arithmeticSeriesSum(int n) {
    int a = 2;    // 等差数列的首项
    int d = 3;    // 等差数列的公差
    int sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        sum += a + i * d;
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int sum = arithmeticSeriesSum(n);
    printf("%d\n", sum);

    return 0;
}

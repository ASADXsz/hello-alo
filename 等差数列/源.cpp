#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int arithmeticSeriesSum(int n) {
    int a = 2;    // �Ȳ����е�����
    int d = 3;    // �Ȳ����еĹ���
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

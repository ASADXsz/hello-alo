#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // 输入整数个数

    int num, count_negative = 0, count_positive = 0;
    double sum_positive = 0.0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);  // 输入整数
        if (num < 0) {
            count_negative++;  // 统计负数个数
        }
        else if (num > 0) {
            count_positive++;  // 统计正数个数
            sum_positive += num;  // 累加正数
        }
    }

    // 计算正数的平均值
    double avg_positive = (count_positive > 0) ? sum_positive / count_positive : 0.0;

    printf("%d %.1f\n", count_negative, avg_positive);  // 输出负数个数和正数平均值

    return 0;
}
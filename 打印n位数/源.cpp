#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* printNumbers(int n, int* returnSize) {
    // 计算最大的n位数
    int maxNumber = pow(10, n) - 1;

    // 分配存储整数数组的内存
    int* numbers = (int*)malloc(maxNumber * sizeof(int));

    // 逐个填充整数数组
    for (int i = 0; i < maxNumber; i++) {
        numbers[i] = i + 1;
    }

    // 设置返回数组的大小
    *returnSize = maxNumber;

    return numbers;
}

int main() {
    int n;
    printf("请输入n的值：");
    scanf("%d", &n);

    int size;
    int* numbers = printNumbers(n, &size);

    printf("从1到%d位的数字为：", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    // 释放内存
    free(numbers);

    return 0;
}
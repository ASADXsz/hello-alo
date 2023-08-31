#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* printNumbers(int n, int* returnSize) {
    // ��������nλ��
    int maxNumber = pow(10, n) - 1;

    // ����洢����������ڴ�
    int* numbers = (int*)malloc(maxNumber * sizeof(int));

    // ��������������
    for (int i = 0; i < maxNumber; i++) {
        numbers[i] = i + 1;
    }

    // ���÷�������Ĵ�С
    *returnSize = maxNumber;

    return numbers;
}

int main() {
    int n;
    printf("������n��ֵ��");
    scanf("%d", &n);

    int size;
    int* numbers = printNumbers(n, &size);

    printf("��1��%dλ������Ϊ��", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    // �ͷ��ڴ�
    free(numbers);

    return 0;
}
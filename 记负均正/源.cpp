#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // ������������

    int num, count_negative = 0, count_positive = 0;
    double sum_positive = 0.0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);  // ��������
        if (num < 0) {
            count_negative++;  // ͳ�Ƹ�������
        }
        else if (num > 0) {
            count_positive++;  // ͳ����������
            sum_positive += num;  // �ۼ�����
        }
    }

    // ����������ƽ��ֵ
    double avg_positive = (count_positive > 0) ? sum_positive / count_positive : 0.0;

    printf("%d %.1f\n", count_negative, avg_positive);  // �����������������ƽ��ֵ

    return 0;
}
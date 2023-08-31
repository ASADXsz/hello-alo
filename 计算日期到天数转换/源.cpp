#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// �ж��Ƿ�Ϊ����
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ÿ���µ�����
int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int dayOfYear(int year, int month, int day) {
    // ��������꣬���·���29��
    if (isLeapYear(year)) {
        monthDays[1] = 29;
    }

    // ��������
    int total = 0;
    for (int i = 0; i < month - 1; i++) {
        total += monthDays[i];
    }
    total += day;

    // ���ö��µ�����
    monthDays[1] = 28;

    return total;
}

int main() {
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    printf("%d\n", dayOfYear(year, month, day));
    return 0;
}
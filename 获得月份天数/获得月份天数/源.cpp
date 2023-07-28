#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int isLeapYear(int year) {
    // �ж��Ƿ�������
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;  // ������
    }
    else {
        return 0;  // ��������
    }
}

int getDaysOfMonth(int year, int month) {
    // ������ݺ��·ݼ���������ж�����
    int days;

    // �ж�ÿ���µ�����
    switch (month) {
    case 2:
        if (isLeapYear(year)) {
            days = 29;  // �����2����29��
        }
        else {
            days = 28;  // �������2����28��
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;  // 4�¡�6�¡�9�¡�11�¶���30��
        break;
    default:
        days = 31;  // �����·ݶ���31��
        break;
    }

    return days;
}

int main() {
    int year, month;

    while (scanf("%d %d", &year, &month) == 2) {  // ѭ����ȡ����
        int days = getDaysOfMonth(year, month);  // ��ȡ��һ������µ�����
        printf("%d\n", days);  // ������
    }

    return 0;
}
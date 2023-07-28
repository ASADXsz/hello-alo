#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int isLeapYear(int year) {
    // 判断是否是闰年
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;  // 是闰年
    }
    else {
        return 0;  // 不是闰年
    }
}

int getDaysOfMonth(int year, int month) {
    // 根据年份和月份计算这个月有多少天
    int days;

    // 判断每个月的天数
    switch (month) {
    case 2:
        if (isLeapYear(year)) {
            days = 29;  // 闰年的2月有29天
        }
        else {
            days = 28;  // 非闰年的2月有28天
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;  // 4月、6月、9月、11月都有30天
        break;
    default:
        days = 31;  // 其他月份都有31天
        break;
    }

    return days;
}

int main() {
    int year, month;

    while (scanf("%d %d", &year, &month) == 2) {  // 循环读取输入
        int days = getDaysOfMonth(year, month);  // 获取这一年这个月的天数
        printf("%d\n", days);  // 输出结果
    }

    return 0;
}
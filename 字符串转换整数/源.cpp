#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    // 去除前导空格
    while (*s == ' ') {
        s++;
    }

    // 判断正负号
    int sign = 1;
    if (*s == '+' || *s == '-') {
        if (*s == '-') {
            sign = -1;
        }
        s++;
    }

    // 转换数字
    int result = 0;
    while (isdigit(*s)) {
        int digit = *s - '0';

        // 检查是否超过范围
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        s++;
    }

    return result * sign;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows) {
    int len = strlen(s);

    // 处理特殊情况
    if (numRows == 1 || len <= numRows) {
        return s;
    }

    // 计算每个Z字形周期的长度
    int cycleLen = 2 * numRows - 2;

    // 创建新的字符串数组
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    // 遍历每一行
    for (int i = 0; i < numRows; i++) {
        // 遍历每个Z字形周期
        for (int j = i; j < len; j += cycleLen) {
            result[index++] = s[j];

            // 处理非首行和尾行的字符
            if (i != 0 && i != numRows - 1) {
                int zigIndex = j + cycleLen - 2 * i;
                if (zigIndex < len) {
                    result[index++] = s[zigIndex];
                }
            }
        }
    }

    result[index] = '\0';

    return result;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <corecrt_malloc.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    // 如果字符串数组为空或数组大小为0，返回空字符串
    if (strs == NULL || strsSize == 0) {
        return "";
    }

    // 找到数组中最短字符串的长度
    int shortestLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < shortestLen) {
            shortestLen = len;
        }
    }

    // 为前缀分配内存
    char* prefix = (char*)malloc(sizeof(char) * (shortestLen + 1));
    prefix[0] = '\0';

    // 检查第一个字符串中的每个字符
    for (int idx = 0; idx < shortestLen; idx++) {
        char c = strs[0][idx];
        // 将字符与其他字符串中相应的字符进行比较
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][idx] != c) {
                prefix[idx] = '\0';
                return prefix;
            }
        }
        prefix[idx] = c;
    }
    prefix[shortestLen] = '\0';
    return prefix;
}
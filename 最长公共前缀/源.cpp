#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <corecrt_malloc.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    // ����ַ�������Ϊ�ջ������СΪ0�����ؿ��ַ���
    if (strs == NULL || strsSize == 0) {
        return "";
    }

    // �ҵ�����������ַ����ĳ���
    int shortestLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < shortestLen) {
            shortestLen = len;
        }
    }

    // Ϊǰ׺�����ڴ�
    char* prefix = (char*)malloc(sizeof(char) * (shortestLen + 1));
    prefix[0] = '\0';

    // ����һ���ַ����е�ÿ���ַ�
    for (int idx = 0; idx < shortestLen; idx++) {
        char c = strs[0][idx];
        // ���ַ��������ַ�������Ӧ���ַ����бȽ�
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
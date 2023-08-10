#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows) {
    int len = strlen(s);

    // �����������
    if (numRows == 1 || len <= numRows) {
        return s;
    }

    // ����ÿ��Z�������ڵĳ���
    int cycleLen = 2 * numRows - 2;

    // �����µ��ַ�������
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    // ����ÿһ��
    for (int i = 0; i < numRows; i++) {
        // ����ÿ��Z��������
        for (int j = i; j < len; j += cycleLen) {
            result[index++] = s[j];

            // ��������к�β�е��ַ�
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
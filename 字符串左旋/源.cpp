#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void leftRotateString(char* str, int k) {
    int len = strlen(str);
    // 对于k大于字符串长度的情况，取模以防越界
    k = k % len;

    // 左旋k个字符
    for (int i = 0; i < k; i++) {
        char temp = str[0];
        for (int j = 0; j < len - 1; j++) {
            str[j] = str[j + 1];
        }
        str[len - 1] = temp;
    }
}

int main() {
    char str[] = "ABCD";
    int k = 2;

    printf("原始字符串: %s\n", str);
    leftRotateString(str, k);
    printf("左旋后的字符串: %s\n", str);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int isRotatedString(const char* s1, const char* s2) {
    int len1 = 0, len2 = 0;
    int i, j;

    // 计算s1和s2的长度
    while (s1[len1] != '\0') {
        len1++;
    }
    while (s2[len2] != '\0') {
        len2++;
    }

    // 长度不相等则一定不是旋转后的字符串
    if (len1 != len2) {
        return 0;
    }

    // 查找s2是否为s1旋转后的字符串
    for (i = 0; i < len1; i++) {
        int found = 1;

        for (j = 0; j < len1; j++) {
            int index = (i + j) % len1;
            if (s1[j] != s2[index]) {
                found = 0;
                break;
            }
        }

        if (found) {
            return 1;
        }
    }

    return 0;
}

int main() {
    const char* s1 = "AABCD";
    const char* s2 = "BCDAA";

    printf("判断结果: %d\n", isRotatedString(s1, s2));

    return 0;
}
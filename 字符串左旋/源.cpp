#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void leftRotateString(char* str, int k) {
    int len = strlen(str);
    // ����k�����ַ������ȵ������ȡģ�Է�Խ��
    k = k % len;

    // ����k���ַ�
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

    printf("ԭʼ�ַ���: %s\n", str);
    leftRotateString(str, k);
    printf("��������ַ���: %s\n", str);

    return 0;
}
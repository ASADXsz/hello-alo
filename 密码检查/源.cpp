#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isPasswordValid(char* password) {
    int length = 0;
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int digitCount = 0;

    // ������볤���Ƿ�����Ϊ8
    while (password[length] != '\0') {
        length++;
    }
    if (length < 8) {
        return false;
    }

    // ��������Ƿ������ֿ�ͷ
    if (isdigit(password[0])) {
        return false;
    }

    // ����������ַ����͵�����
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercaseCount++;
        }
        else if (isupper(password[i])) {
            uppercaseCount++;
        }
        else if (isdigit(password[i])) {
            digitCount++;
        }
    }

    // ��������ַ����͵�Ҫ��
    int typeCount = 0;
    if (lowercaseCount > 0) {
        typeCount++;
    }
    if (uppercaseCount > 0) {
        typeCount++;
    }
    if (digitCount > 0) {
        typeCount++;
    }
    if (typeCount < 2) {
        return false;
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char password[101];
        scanf("%s", password);

        if (isPasswordValid(password)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
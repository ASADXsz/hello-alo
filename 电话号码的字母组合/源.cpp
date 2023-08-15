#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ӳ���
char mapping[10][5] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// �ݹ�������ĸ���
void generateCombinations(char* digits, char** combinations, int* count, char* current, int index) {
    if (digits[index] == '\0') {
        // ��ǰ������ϴ�����ϣ�����ǰ�����ӵ��������
        combinations[*count] = strdup(current);
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    int len = strlen(mapping[digit]);

    // ������ǰ���ֶ�Ӧ��������ĸ
    for (int i = 0; i < len; i++) {
        current[index] = mapping[digit][i];
        generateCombinations(digits, combinations, count, current, index + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int digitsLen = strlen(digits);
    int maxCombinations = 1;

    // ����������Ĵ�С
    for (int i = 0; i < digitsLen; i++) {
        maxCombinations *= strlen(mapping[digits[i] - '0']);
    }

    char** combinations = (char**)malloc(maxCombinations * sizeof(char*));

    char* current = (char*)malloc((digitsLen + 1) * sizeof(char));
    current[digitsLen] = '\0';

    *returnSize = 0;
    generateCombinations(digits, combinations, returnSize, current, 0);

    free(current);

    return combinations;
}

int main() {
    char digits[] = "23";
    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);

    printf("Letter Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
    }

    // �ͷ��ڴ�
    for (int i = 0; i < returnSize; i++) {
        free(combinations[i]);
    }
    free(combinations);

    return 0;
}
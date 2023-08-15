#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 映射表
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

// 递归生成字母组合
void generateCombinations(char* digits, char** combinations, int* count, char* current, int index) {
    if (digits[index] == '\0') {
        // 当前数字组合处理完毕，将当前结果添加到结果集中
        combinations[*count] = strdup(current);
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    int len = strlen(mapping[digit]);

    // 遍历当前数字对应的所有字母
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

    // 计算结果数组的大小
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

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(combinations[i]);
    }
    free(combinations);

    return 0;
}
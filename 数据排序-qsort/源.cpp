#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，用于指定排序的顺序
int compare_int(const void* a, const void* b) {
    // 将指针转换为对应类型的指针，并进行比较
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int compare_float(const void* a, const void* b) {
    float arg1 = *(const float*)a;
    float arg2 = *(const float*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int compare_string(const void* a, const void* b) {
    const char* arg1 = *(const char**)a;
    const char* arg2 = *(const char**)b;

    return strcmp(arg1, arg2);
}

int main() {
    int int_arr[] = { 9, 5, 2, 7, 1 };
    int int_arr_len = sizeof(int_arr) / sizeof(int);

    float float_arr[] = { 9.3, 5.7, 2.1, 7.9, 1.2 };
    int float_arr_len = sizeof(float_arr) / sizeof(float);

    const char* str_arr[] = { "橘子", "苹果", "香蕉", "樱桃" };
    int str_arr_len = sizeof(str_arr) / sizeof(const char*);

    // 对整型数组进行排序
    qsort(int_arr, int_arr_len, sizeof(int), compare_int);

    printf("排序后的整型数组：");
    for (int i = 0; i < int_arr_len; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // 对浮点型数组进行排序
    qsort(float_arr, float_arr_len, sizeof(float), compare_float);

    printf("排序后的浮点型数组：");
    for (int i = 0; i < float_arr_len; i++) {
        printf("%.2f ", float_arr[i]);
    }
    printf("\n");

    // 对字符串数组进行排序
    qsort(str_arr, str_arr_len, sizeof(const char*), compare_string);

    printf("排序后的字符串数组：");
    for (int i = 0; i < str_arr_len; i++) {
        printf("%s ", str_arr[i]);
    }
    printf("\n");

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ȽϺ���������ָ�������˳��
int compare_int(const void* a, const void* b) {
    // ��ָ��ת��Ϊ��Ӧ���͵�ָ�룬�����бȽ�
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

    const char* str_arr[] = { "����", "ƻ��", "�㽶", "ӣ��" };
    int str_arr_len = sizeof(str_arr) / sizeof(const char*);

    // �����������������
    qsort(int_arr, int_arr_len, sizeof(int), compare_int);

    printf("�������������飺");
    for (int i = 0; i < int_arr_len; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // �Ը����������������
    qsort(float_arr, float_arr_len, sizeof(float), compare_float);

    printf("�����ĸ��������飺");
    for (int i = 0; i < float_arr_len; i++) {
        printf("%.2f ", float_arr[i]);
    }
    printf("\n");

    // ���ַ��������������
    qsort(str_arr, str_arr_len, sizeof(const char*), compare_string);

    printf("�������ַ������飺");
    for (int i = 0; i < str_arr_len; i++) {
        printf("%s ", str_arr[i]);
    }
    printf("\n");

    return 0;
}
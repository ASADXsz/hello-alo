#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

void mergeArrays(int arr1[], int n, int arr2[], int m, int result[]) {
    int i = 0, j = 0, k = 0;

    // ���������а�������ϲ���result������
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {  // �������1�ĵ�ǰԪ��С������2�ĵ�ǰԪ��
            result[k] = arr1[i];  // ������1�ĵ�ǰԪ����ӵ�result��
            i++;  // �ƶ�������1����һ��Ԫ��
        }
        else {
            result[k] = arr2[j];  // ���򣬽�����2�ĵ�ǰԪ����ӵ�result��
            j++;  // �ƶ�������2����һ��Ԫ��
        }
        k++;  // �ƶ���result����һ��λ��
    }

    // ��ʣ���Ԫ�ؿ�����result������
    while (i < n) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // ��ȡ�����n��m

    int* sequence1 = (int*)malloc(n * sizeof(int));
    int* sequence2 = (int*)malloc(m * sizeof(int));
    int* result = (int*)malloc((n + m) * sizeof(int));

    // ��ȡ��һ����������
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence1[i]);
    }

    // ��ȡ�ڶ�����������
    for (int i = 0; i < m; i++) {
        scanf("%d", &sequence2[i]);
    }

    mergeArrays(sequence1, n, sequence2, m, result);  // �ϲ���������

    // ����ϲ������������
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
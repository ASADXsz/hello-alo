#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

void mergeArrays(int arr1[], int n, int arr2[], int m, int result[]) {
    int i = 0, j = 0, k = 0;

    // 将两个序列按照升序合并到result数组中
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {  // 如果序列1的当前元素小于序列2的当前元素
            result[k] = arr1[i];  // 将序列1的当前元素添加到result中
            i++;  // 移动到序列1的下一个元素
        }
        else {
            result[k] = arr2[j];  // 否则，将序列2的当前元素添加到result中
            j++;  // 移动到序列2的下一个元素
        }
        k++;  // 移动到result的下一个位置
    }

    // 将剩余的元素拷贝到result数组中
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
    scanf("%d %d", &n, &m);  // 读取输入的n和m

    int* sequence1 = (int*)malloc(n * sizeof(int));
    int* sequence2 = (int*)malloc(m * sizeof(int));
    int* result = (int*)malloc((n + m) * sizeof(int));

    // 读取第一个升序序列
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence1[i]);
    }

    // 读取第二个升序序列
    for (int i = 0; i < m; i++) {
        scanf("%d", &sequence2[i]);
    }

    mergeArrays(sequence1, n, sequence2, m, result);  // 合并两个序列

    // 输出合并后的升序序列
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            result[0] = abs(nums[i]);
        }
        else {
            nums[index] = -nums[index];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[1] = i + 1;
            break;
        }
    }

    *returnSize = 2;

    return result;
}

int main() {
    int nums[] = { 1, 2, 2, 4 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = findErrorNums(nums, numsSize, &returnSize);

    printf("[%d, %d]\n", result[0], result[1]);

    free(result);

    return 0;
}
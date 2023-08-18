#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int* left = nums;
    int* right = nums + numsSize - 1;

    while (left <= right) {
        int* mid = left + (right - left) / 2;
        if (*mid == target) {
            return mid - nums;
        }
        else if (*mid < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left - nums;
}

int main() {
    int nums[] = { 1, 3, 5, 6 };
    int target = 5;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int index = searchInsert(nums, numsSize, target);
    printf("%d\n", index);
    return 0;
}
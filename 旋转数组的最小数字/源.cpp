#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // 最小值在mid的右侧
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            // 最小值在mid的左侧或者就是mid本身
            right = mid;
        }
        else {
            // 当出现重复元素时，无法确定最小值的位置，缩小搜索范围
            right--;
        }
    }

    return nums[left];
}

int main() {
    int nums[] = { 3, 4, 5, 1, 2 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int min = findMin(nums, numsSize);
    printf("旋转数组中的最小值为：%d\n", min);

    return 0;
}
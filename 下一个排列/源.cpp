#define _CRT_SECURE_NO_WARNINGS 1
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    // 反转指定范围内的元素
    int start = i + 1;
    int end = numsSize - 1;
    while (start < end) {
        swap(nums, start, end);
        start++;
        end--;
    }
}
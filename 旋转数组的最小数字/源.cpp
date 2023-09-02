#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // ��Сֵ��mid���Ҳ�
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            // ��Сֵ��mid�������߾���mid����
            right = mid;
        }
        else {
            // �������ظ�Ԫ��ʱ���޷�ȷ����Сֵ��λ�ã���С������Χ
            right--;
        }
    }

    return nums[left];
}

int main() {
    int nums[] = { 3, 4, 5, 1, 2 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int min = findMin(nums, numsSize);
    printf("��ת�����е���СֵΪ��%d\n", min);

    return 0;
}
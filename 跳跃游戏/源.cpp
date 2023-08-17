#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
//贪心算法
bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            // 无法到达当前位置
            return false;
        }

        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;

        if (maxReach >= numsSize - 1) {
            // 已经可以到达最后一个下标
            return true;
        }
    }

    return true;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
//̰���㷨
bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            // �޷����ﵱǰλ��
            return false;
        }

        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;

        if (maxReach >= numsSize - 1) {
            // �Ѿ����Ե������һ���±�
            return true;
        }
    }

    return true;
}
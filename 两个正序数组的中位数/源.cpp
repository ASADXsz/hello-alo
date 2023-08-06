#include <stdio.h>
#include <stdlib.h>
#include<math.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) { // 保证 nums1 是较短的数组
        int* temp = nums1; nums1 = nums2; nums2 = temp;
        int tmp = nums1Size; nums1Size = nums2Size; nums2Size = tmp;
    }
    int iMin = 0, iMax = nums1Size, halfLen = (nums1Size + nums2Size + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < nums1Size && nums2[j - 1] > nums1[i]) {
            iMin = i + 1; // i 太小
        }
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            iMax = i - 1; // i 太大
        }
        else { // i 正好
            int maxOfLeft;
            if (i == 0) { maxOfLeft = nums2[j - 1]; }
            else if (j == 0) { maxOfLeft = nums1[i - 1]; }
            else { maxOfLeft = fmax(nums1[i - 1], nums2[j - 1]); }
            if ((nums1Size + nums2Size) % 2 == 1) { return maxOfLeft; }

            int minOfRight;
            if (i == nums1Size) { minOfRight = nums2[j]; }
            else if (j == nums2Size) { minOfRight = nums1[i]; }
            else { minOfRight = fmin(nums1[i], nums2[j]); }

            return (maxOfLeft + minOfRight) / 2.0;
        }
    }
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
int GetNumberOfK(int* nums, int numsLen, int k) {
    if (nums == nullptr || numsLen == 0)
        return 0;

    int first = GetFirstK(nums, numsLen, k);
    int last = GetLastK(nums, numsLen, k);

    if (first != -1 && last != -1)
        return last - first + 1;

    return 0;
}

int GetFirstK(int* nums, int numsLen, int k) {
    int start = 0;
    int end = numsLen - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < k)
            start = mid + 1;
        else if (nums[mid] > k)
            end = mid - 1;
        else {
            if (mid == 0 || nums[mid - 1] != k)
                return mid;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int GetLastK(int* nums, int numsLen, int k) {
    int start = 0;
    int end = numsLen - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < k)
            start = mid + 1;
        else if (nums[mid] > k)
            end = mid - 1;
        else {
            if (mid == numsLen - 1 || nums[mid + 1] != k)
                return mid;
            else
                start = mid + 1;
        }
    }

    return -1;
}
int GetNumberOfK(int* nums, int numsLen, int k) {
    if (nums == nullptr || numsLen == 0)
        return 0;

    int first = GetFirstK(nums, numsLen, k);
    int last = GetLastK(nums, numsLen, k);

    if (first != -1 && last != -1)
        return last - first + 1;

    return 0;
}
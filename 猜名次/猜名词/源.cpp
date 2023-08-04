#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

#define N 5
bool used[N + 1] = {false};

void dfs(int depth, int nums[]) {
    if (depth == N + 1) { // 找到一个满足条件的组合
        if ((2 == nums[2] && 3 != nums[1]) || (2 != nums[2] && 3 == nums[1]))
            if ((2 == nums[2] && 4 != nums[5]) || (2 != nums[2] && 4 == nums[5]))
                if ((1 == nums[3] && 2 != nums[4]) || (1 != nums[3] && 2 == nums[4]))
                    if ((5 == nums[3] && 3 != nums[4]) || (5 != nums[3] && 3 == nums[4]))
                        if ((4 == nums[5] && 1 != nums[1]) || (4 != nums[5] && 1 == nums[1]))
                            printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", nums[1], nums[2], nums[3], nums[4], nums[5]);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            used[i] = true;
            nums[depth] = i;
            dfs(depth + 1, nums);
            used[i] = false;
        }
    }
}

int main() {
    int nums[N + 1];
    dfs(1, nums);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int s_len = strlen(s);
    int p_len = strlen(p);

    bool dp[s_len + 1][p_len + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;

    // 处理模式串前部分为'*'的情况
    for (int j = 2; j <= p_len; j += 2) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= p_len; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                // 当前字符匹配，继承前面的结果
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                // 当前字符为'*'，有两种情况
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    // 匹配多个字符 或 匹配零个字符
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                }
                else {
                    // 匹配零个字符
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }

    return dp[s_len][p_len];
}
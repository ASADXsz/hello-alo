#define _CRT_SECURE_NO_WARNINGS 1
char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) < 1) {
        return "";
    }

    int n = strlen(s);
    int start = 0, end = 0;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = len1 > len2 ? len1 : len2;

        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    char* result = (char*)malloc((end - start + 2) * sizeof(char));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}

int expandAroundCenter(char* s, int left, int right) {
    int n = strlen(s);

    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}
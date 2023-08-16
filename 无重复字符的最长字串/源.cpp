#define _CRT_SECURE_NO_WARNINGS 1
int lengthOfLongestSubstring(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    int maxLength = 0;
    int start = 0;
    int visited[128];

    for (int i = 0; i < 128; i++) {
        visited[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int currentChar = s[i];
        if (visited[currentChar] >= start) {
            start = visited[currentChar] + 1;
        }
        visited[currentChar] = i;
        int length = i - start + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}
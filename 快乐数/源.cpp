#define _CRT_SECURE_NO_WARNINGS 1
// 计算下一个数
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        totalSum += d * d;
    }
    return totalSum;
}

// 判断是否为快乐数
int isHappy(int n) {
    int slowRunner = n;
    int fastRunner = getNext(n);
    while (fastRunner != 1 && slowRunner != fastRunner) {
        slowRunner = getNext(slowRunner);
        fastRunner = getNext(getNext(fastRunner));
    }
    return fastRunner == 1;
}
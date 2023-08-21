#define _CRT_SECURE_NO_WARNINGS 1
// ������һ����
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        totalSum += d * d;
    }
    return totalSum;
}

// �ж��Ƿ�Ϊ������
int isHappy(int n) {
    int slowRunner = n;
    int fastRunner = getNext(n);
    while (fastRunner != 1 && slowRunner != fastRunner) {
        slowRunner = getNext(slowRunner);
        fastRunner = getNext(getNext(fastRunner));
    }
    return fastRunner == 1;
}
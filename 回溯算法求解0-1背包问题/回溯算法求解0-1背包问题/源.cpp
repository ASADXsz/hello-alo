#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

// 0-1背包问题的回溯算法
void backtrack(vector<int>& weights, vector<int>& values, int capacity, int currentWeight, int currentValue, int index, int& maxValue) {
    // 达到背包容量或搜索完所有物品时更新最大价值
    if (currentWeight > capacity || index == weights.size()) {
        if (currentValue > maxValue) {
            maxValue = currentValue;
        }
        return;
    }

    // 选择当前物品
    if (currentWeight + weights[index] <= capacity) {
        backtrack(weights, values, capacity, currentWeight + weights[index], currentValue + values[index], index + 1, maxValue);
    }

    // 不选择当前物品
    backtrack(weights, values, capacity, currentWeight, currentValue, index + 1, maxValue);
}

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int maxValue = 0;
    backtrack(weights, values, capacity, 0, 0, 0, maxValue);
    return maxValue;
}

int main() {
    vector<int> weights = { 2, 3, 4, 5 };
    vector<int> values = { 3, 4, 5, 6 };
    int capacity = 8;

    int maxValue = knapsack(weights, values, capacity);
    cout << "Max value: " << maxValue << endl;

    return 0;
}
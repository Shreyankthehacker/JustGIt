#include "knapsack.h"
#include <algorithm>

using namespace std;

Knapsack::Knapsack(int W, const vector<int>& weights, const vector<int>& values)
    : W(W), weights(weights), values(values) {}

int Knapsack::solve() {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

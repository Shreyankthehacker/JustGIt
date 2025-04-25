#include "matrix_chain.h"
#include <vector>
#include <climits>
using namespace std;

int solve(int i, int j, const vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; ++k) {
        int cost = solve(i, k, arr, dp) + solve(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
        if (cost < minCost) minCost = cost;
    }

    return dp[i][j] = minCost;
}

int matrixChainMultiplication(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(1, n - 1, arr, dp);
}

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 * Runtime: 164ms
 * Time Complexity: O(N^2)
 * Description: Top-down DP
 */

class Solution {
private:
  int** dp;
  int minCost(int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return i + 1;

    if (dp[i][j] != -1)
      return dp[i][j];

    dp[i][j] = min(minCost(i + 1, j), minCost(i, j - 1));
    for (int k = i + 1; k < j; k++) {
      dp[i][j] = min(minCost(i, k - 1) + minCost(k + 1, j));
    }
    return dp[i][j];
  }
public:
  int getMoneyAmount(int n) {
    dp = new int*[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new int[n];
      memset(dp[i], -1, sizeof(int) * n);
    }
    return minCost(0, n - 1);
  }
};


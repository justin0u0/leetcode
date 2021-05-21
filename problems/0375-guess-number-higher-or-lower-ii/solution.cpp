/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 * Runtime: 40ms
 */

class Solution {
public:
  int getMoneyAmount(int n) {
    int** dp = new int*[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new int[n]();
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = min((i + 1) + dp[i + 1][j], dp[i][j - 1] + (j + 1));
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + (k + 1));
        }
      }
    }
    return dp[0][n - 1];
  }
};


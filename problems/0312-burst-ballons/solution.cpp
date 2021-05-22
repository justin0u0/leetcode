/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/burst-balloons/
 * Runtime: 372ms
 */

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    int **dp = new int*[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new int[n]();
    }

    dp[n - 1][n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      dp[i][i] = nums[i];
      dp[i][i + 1] = nums[i] * nums[i + 1];
      for (int j = i + 2; j < n; j++) {
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k - 1] * nums[k] * nums[k + 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};


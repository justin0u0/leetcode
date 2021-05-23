/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/burst-balloons/
 * Runtime: 372ms
 * Time Complexity: O(N^3)
 */

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.emplace_back(1);
    int n = nums.size();
    
    int **dp = new int*[n];
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = new int[n + 1];
      dp[i][i + 1] = 0;

      for (int j = i + 2; j < n; j++) {
        for (int k = i + 1; k < j; k++)
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
      }
    }
    return dp[0][n - 1];
  }
};


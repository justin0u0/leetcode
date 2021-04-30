/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/combination-sum-iv/
 * Runtime: 0ms
 */

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    unsigned int* dp = new unsigned int[target + 1]();
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
      for (int value : nums) {
        if (i >= value)
          dp[i] += dp[i - value];
      }
    }
    return dp[target];
  }
};


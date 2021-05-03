/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/house-robber/
 * Runtime: 0ms
 * Description: Another transition
 */

class Solution {
public:
  int rob(vector<int>& nums) {
    int dp1 = 0, dp2 = 0, dp3 = 0;
    for (int& num : nums) {
      int dp = dp1 + dp2 + num;
      dp1 = dp2;
      dp2 = dp3;
      dp3 = dp;
    }
    return max(dp2, dp3);
  }
};


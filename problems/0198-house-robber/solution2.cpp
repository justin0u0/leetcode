/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/house-robber/
 * Runtime: 0ms
 * Space: O(1)
 */

class Solution {
public:
  int rob(vector<int>& nums) {
    int dp1 = 0, dp2 = 0;
    for (int& num : nums) {
      int tmp = dp1;
      dp1 = dp2 + num;
      dp2 = max(tmp, dp2);
    }
    return max(dp1, dp2);
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/house-robber/
 * Runtime: 0ms
 * Space: O(N)
 */

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    int* dp1 = new int[n](); // Take
    int* dp2 = new int[n](); // No

    dp1[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp1[i] = dp2[i - 1] + nums[i];
      dp2[i] = max(dp1[i - 1], dp2[i - 1]);
    }
    return max(dp1[n - 1], dp2[n - 1]);
  }
};


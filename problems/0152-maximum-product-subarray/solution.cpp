/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-subarray/
 * Runtime: 4ms
 * Space: O(N)
 */

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int* dp1 = new int[n]();
    int* dp2 = new int[n]();
    if (nums[0] >= 0)
      dp1[0] = nums[0];
    else
      dp2[0] = nums[0];

    int maxValue = nums[0];
    for (int i = 1; i < n; i++) {
      maxValue = max(maxValue, nums[i]);
      if (nums[i] >= 0) {
        dp1[i] = max(nums[i], dp1[i - 1] * nums[i]);
        dp2[i] = dp2[i - 1] * nums[i];
      } else {
        dp1[i] = dp2[i - 1] * nums[i];
        dp2[i] = min(nums[i], dp1[i - 1] * nums[i]);
      }
    }
    if (maxValue < 0)
      return maxValue;
    for (int i = 0; i < n; i++)
      maxValue = max(maxValue, dp1[i]);
    return maxValue;
  }
};


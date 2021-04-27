/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-subarray/
 * Runtime: 4ms
 * Space: O(1)
 */

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int dp1 = 0, dp2 = 0;
    if (nums[0] >= 0)
      dp1 = nums[0];
    else
      dp2 = nums[0];

    int answer = dp1;
    for (int i = 1; i < n; i++) {
      int maxValue = max(dp1 * nums[i], dp2 * nums[i]);
      int minValue = min(dp1 * nums[i], dp2 * nums[i]);
      dp1 = max(nums[i], maxValue);
      dp2 = min(nums[i], minValue);
      answer = max(answer, dp1);
    }
    return answer;
  }
};


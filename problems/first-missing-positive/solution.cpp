/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        swap(nums[nums[i] - 1], nums[i]);
    }
    for (int i = 0; i < n; i++)
      if (nums[i] != i + 1)
        return i + 1;
    return n + 1;
  }
};


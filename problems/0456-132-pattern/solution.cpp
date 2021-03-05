/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/132-pattern/
 * Runtime: 12ms
 */

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> minValues(n);

    int minValue = nums[0];
    for (int i = 0; i < n; i++) {
      minValues[i] = minValue;
      minValue = min(minValue, nums[i]);
    }
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && stk.top() <= minValues[i])
        stk.pop();
      if (!stk.empty() && stk.top() < nums[i])
        return true;
      stk.push(nums[i]);
    }
    return false;
  }
};


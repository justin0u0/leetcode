/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/split-array-largest-sum/
 * Runtime: 0ms
 */

class Solution {
private:
  bool validate(vector<int>& nums, int limit, int m) {
    int sum = limit;
    for (auto num: nums) {
      if (num > limit)
        return false;
      sum += num;
      if (sum > limit) {
        sum = num;
        m--;
      }
    }
    return (m >= 0);
  }
public:
  int splitArray(vector<int>& nums, int m) {
    int minSum = 0, maxSum = 1e9 + 10;
    while (minSum < maxSum) {
      int limit = (minSum + maxSum) / 2;
      if (validate(nums, limit, m))
        maxSum = limit;
      else
        minSum = limit + 1;
    }
    return maxSum;
  }
};


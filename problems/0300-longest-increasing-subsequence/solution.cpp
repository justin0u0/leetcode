/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-increasing-subsequence/
 * Runtime: 8ms
 */

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> lis{-10001};
    for (int num: nums) {
      if (num > lis.back())
        lis.emplace_back(num);
      else
        *lower_bound(lis.begin(), lis.end(), num) = num;
    }
    return (int)lis.size() - 1;
  }
};


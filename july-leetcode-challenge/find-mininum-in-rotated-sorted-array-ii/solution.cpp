/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/
 */

class Solution {
public:
  int findMin(vector<int>& nums) {
    int minValue = 0x7fffffff;
    for (auto num: nums) minValue = min(minValue, num);
    return minValue;
  }
};


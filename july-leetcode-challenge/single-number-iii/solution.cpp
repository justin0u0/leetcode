/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/
 */

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int xorAll = 0;
    for (auto num: nums) xorAll ^= num;

    int key = 1 << __builtin_ctz(xorAll);

    vector<int> singleNumbers(2);
    for (auto num: nums) singleNumbers[!(num & key)] ^= num;
    return singleNumbers;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/
 */

class Solution {
public:
  int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }
};


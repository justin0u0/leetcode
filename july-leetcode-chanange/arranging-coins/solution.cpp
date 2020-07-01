/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
 */

class Solution {
public:
  int arrangeCoins(int n) {
    int l = 0, r = 65536;
    while (l < r) {
      int mid = (l + r) / 2;
      if (1LL * mid * (mid + 1) / 2 <= n)
        l = mid + 1;
      else
        r = mid;
    }
    return l - 1;
  }
};


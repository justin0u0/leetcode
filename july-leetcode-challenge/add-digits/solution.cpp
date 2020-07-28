/**
 * Author: justin0u0<mail@justin0u0.com>
 * https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3402/
 */

class Solution {
public:
  int addDigits(int num) {
    return (num - 1) % 9 + 1;
  }
};


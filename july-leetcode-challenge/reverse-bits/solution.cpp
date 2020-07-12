/**
 * Author: justin0u0<mail@justin0u0.com>
 * Proboem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/
 */

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t reversedNumber = 0;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        reversedNumber |= (1 << (32 - i - 1));
      }
    }
    return reversedNumber;
  }
};

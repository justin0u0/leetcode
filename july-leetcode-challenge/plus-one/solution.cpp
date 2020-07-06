/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
 */

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    bool carry = false;
    digits.back() += 1;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
      digits[i] += carry;
      if (digits[i] > 9) {
        digits[i] -= 10;
        carry = true;
      } else {
        carry = false;
      }
    }
    if (carry) {
      reverse(digits.begin(), digits.end());
      digits.emplace_back(1);
      reverse(digits.begin(), digits.end());
    }
    return digits;
  }
};


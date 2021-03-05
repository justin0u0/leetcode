/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-k-digits/
 * Runtime: 0ms
 */

class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans = "";
    for (char digit: num) {
      while (k && !ans.empty() && digit < ans.back()) {
        ans.pop_back();
        k--;
      }
      if (!ans.empty() || digit != '0') ans.push_back(digit);
    }

    while (!ans.empty() && k--)
      ans.pop_back();
    return ans.empty() ? "0" : ans;
  }
};


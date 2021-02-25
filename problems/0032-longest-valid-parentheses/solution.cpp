/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-valid-parentheses/
 * Runtime: 8ms
 */

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> box;
    box.push(-1);
    int left = -1;
    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++) {
      if (s[i] == '(') {
        box.push(i);
      } else {
        if (box.top() != left) {
          box.pop();
          ans = max(ans, i - box.top());
        } else {
          box.push(i);
          left = i;
        }
      }
    }
    return ans;
  }
};


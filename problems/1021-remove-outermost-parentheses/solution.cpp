/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-outermost-parentheses/
 * Runtime: 4ms
 */

class Solution {
public:
  string removeOuterParentheses(string S) {
    int counter = 0;
    string answer = "";
    for (char ch: S) {
      if (ch == ')') counter--;
      if (counter) answer += ch;
      if (ch == '(') counter++;
    }
    return answer;
  }
};


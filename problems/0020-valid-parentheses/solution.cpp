/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-parentheses/
 * Runtime: 0ms
 */

class Solution {
public:
  bool isValid(string s) {
    stack<char> box;
    for (char ch: s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        box.push(ch);
      } else {
        if (box.empty()
             || (ch == ')' && box.top() != '(')
             || (ch == '}' && box.top() != '{')
             || (ch == ']' && box.top() != '['))
          return false;
        box.pop();
      }
    }
    return box.empty();
  }
};


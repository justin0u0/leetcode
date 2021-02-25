/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-number/
 * Runtime: 0ms
 */

class Solution {
public:
  bool isNumber(string s) {
    int n = (int)s.length();

    int l = 0, r = n - 1;
    while (l < n && s[l] == ' ') l++;
    while (r >= l && s[r] == ' ') r--;

    bool numberVis = false;
    bool eVis = false;
    bool pointVis = false;
    for (int i = l; i <= r; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        numberVis = true;
      } else if (s[i] == '.') {
        if (eVis || pointVis) return false;
        pointVis = true;
      } else if (s[i] == 'e') {
        if (eVis || !numberVis) return false;
        numberVis = false;
        eVis = true;
      } else if (s[i] == '+' || s[i] == '-') {
        if (i != l && s[i - 1] != 'e') return false;
      } else {
        return false;
      }
    }
    return numberVis;
  }
};


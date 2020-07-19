/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/
 */

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.length() < b.length()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < (int)b.length(); i++)
      a[i] += b[i] - '0';
    for (int i = 0; i < (int)a.length(); i++) {
      if (a[i] > '1') {
        if (i != (int)a.length() - 1) a[i + 1]++;
        else a += '1';
        a[i] -= 2;
      }
    }
    reverse(a.begin(), a.end());
    return a;
  }
};


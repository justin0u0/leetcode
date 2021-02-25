/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/wildcard-matching/
 * Runtime: 356ms
 */

class Solution {
public:
  bool isMatch(string s, string p) {
    int sl = (int)s.length();
    int pl = (int)p.length();
    vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1));

    dp[0][0] = true;
    for (int i = 0; i < pl; i++) {
      if (p[i] == '*') dp[0][i + 1] = dp[0][i];
    }

    for (int i = 0; i < sl; i++) {
      for (int j = 0; j < pl; j++) {
        if (p[j] == '*') {
          dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j]);
        } else if (p[j] == '?' || s[i] == p[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        }
      }
    }
    return dp[sl][pl];
  }
};


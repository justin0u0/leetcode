/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/regular-expression-matching/
 */

class Solution {
public:
  bool isMatch(string s, string p) {
    int sLength = (int)s.length();
    int pLength = (int)p.length();

    vector<vector<bool>> dp(sLength + 1, vector<bool>(pLength + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < pLength; i++) {
      if ((i != pLength - 1 && p[i + 1] == '*') || p[i] == '*')
        dp[0][i + 1] = dp[0][i];
    }

    for (int i = 0; i < sLength; i++) {
      for (int j = 0; j < pLength; j++) {
        if (j != pLength - 1 && p[j + 1] == '*') {
          dp[i + 1][j + 1] = dp[i + 1][j];
        } else if ((p[j] == s[i] || p[j] == '.')) {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p[j] == '*') {
          dp[i + 1][j + 1] = (dp[i + 1][j] || (dp[i][j + 1] && (p[j - 1] == s[i] || p[j - 1] == '.')));
        }
      }
    }

    return dp[sLength][pLength];
  }
};


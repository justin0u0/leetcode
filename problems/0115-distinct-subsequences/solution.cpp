/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/distinct-subsequences/
 * Runtime: 0ms
 */

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 0; i <= m; i++)
      dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= m; j++) {
        if (s[j - 1] == t[i - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    return (int)dp[n][m];
  }
};


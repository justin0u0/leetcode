/**
 * Author: jutin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/edit-distance/
 * Runtime: 24ms
 */

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = (int)word1.length();
    int m = (int)word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) dp[i + 1][0] = i + 1;
    for (int i = 0; i < m; i++) dp[0][i + 1] = i + 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (word1[i] == word2[j])
          dp[i + 1][j + 1] = dp[i][j];
        else
          dp[i + 1][j + 1] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
      }
    }
    return dp[n][m];
  }
};


/**
 * Author: jutin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/edit-distance/
 * Runtime: 20ms
 */

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = (int)word1.length();
    int m = (int)word2.length();
    vector<vector<int>> dp(m + 1);

    for (int i = 0; i < m; i++) dp[i + 1] = i + 1;

    for (int i = 0; i < n; i++) {
      int pre = dp[0];
      dp[0] = i + 1;
      for (int j = 0; j < m; j++) {
        int temp = dp[j + 1];
        if (word1[i] == word2[j])
          dp[j + 1] = pre;
        else
          dp[j + 1] = min(min(pre, dp[j + 1]), dp[j]) + 1;
        pre = temp;
      }
    }
    return dp[m];
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/interleaving-string/
 * Runtime: 4ms
 * Time Complexity: O(NM)
 * Space Complexity: O(NM)
 */

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.length();
    int m = s2.length();
    
    if (n + m != s3.length()) return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i || j) {
          dp[i][j] = ((i && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (j && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]));
        }
      }
    }
    return dp[n][m];
  }
};


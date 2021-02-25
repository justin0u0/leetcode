/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/interleaving-string/
 * Runtime: 0ms
 * Time Complexity: O(NM)
 * Space Complexity: O(1)
 */

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.length();
    int m = s2.length();
    
    if (n + m != s3.length()) return false;

    if (n > m) {
      swap(s1, s2);
      swap(n, m);
    }

    vector<bool> dp(m + 1, false);

    dp[0] = true;
    for (int j = 1; j <= m; j++)
      dp[j] = (dp[j - 1] && s2[j - 1] == s3[j - 1]);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[j] = ((dp[j] && s1[i - 1] == s3[i + j - 1]) || (j && dp[j - 1] && s2[j - 1] == s3[i + j - 1]));
      }
    }
    return dp[m];
  }
};


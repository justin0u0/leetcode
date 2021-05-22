/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-partitioning-ii/
 * Runtime: 52ms
 * Description (reverse version):
 *  First calculate isPalindrome for all substring,
 *  then use dp(i) represent the min-cut for substring s[i:n-1],
 *  then dp(i) = min(dp(j) + 1), if isPalindrome(i, j-1) = true
 */

class Solution {
public:
  int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n));
    
    for (int i = n - 1; i >= 0; i--) {
      isPalindrome[i][i] = true;
      isPalindrome[i + 1][i] = true;
      for (int j = i + 1; j < n; j++) {
        isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
      }
    }
    
    int *dp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
      if (isPalindrome[i][n - 1]) {
        dp[i] = 0;
      } else {
        dp[i] = 0x3f3f3f3f;
        for (int j = i + 1; j < n; j++) {
          if (isPalindrome[i][j - 1]) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }
      }
    }
    return dp[0];
  }
};


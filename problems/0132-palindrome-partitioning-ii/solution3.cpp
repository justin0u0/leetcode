/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-partitioning-ii/
 * Runtime: 60ms
 * Time Complexity: O(N^2)
 * Description: One-way O(N^2) solution
 */

class Solution {
public:
  int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n));
    int *dp = new int[n];
    for (int i = n - 1; i >= 0; i--) {
      isPalindrome[i][i] = true;
      isPalindrome[i + 1][i] = true;
      dp[i] = 0x3f3f3f3f;
      for (int j = i + 1; j < n; j++) {
        isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
        if (isPalindrome[i][j - 1]) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
      if (isPalindrome[i][n - 1]) dp[i] = 0;
    }
    return dp[0];
  }
};


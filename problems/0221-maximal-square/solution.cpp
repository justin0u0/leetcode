/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximal-square/
 * Runtime: 20ms
 * Space: O(N^2)
 */

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int** dp = new int*[n];
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
      dp[i] = new int[m]();
      dp[i][0] = matrix[i][0] - '0';
      maxLen = max(maxLen, dp[i][0]);
    }
    for (int i = 0; i < m; i++) {
      dp[0][i] = matrix[0][i] - '0';
      maxLen = max(maxLen, dp[0][i]);
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
          maxLen = max(maxLen, dp[i][j]);
        }
      }
    }
    return maxLen * maxLen;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximal-square/
 * Runtime: 16ms
 * Space: O(N)
 */

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int* dp[2];
    dp[0] = new int[m]();
    dp[1] = new int[m]();

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
      bool cur = i & 1;
      bool pre = cur ^ 1;

      dp[cur][0] = matrix[i][0] - '0';
      maxLen = max(maxLen, dp[cur][0]);
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == '1') {
          dp[cur][j] = min(dp[pre][j - 1], min(dp[pre][j], dp[cur][j - 1])) + 1;
          maxLen = max(maxLen, dp[cur][j]);
        } else {
          dp[cur][j] = 0;
        }
      }
    }
    return maxLen * maxLen;
  }
};


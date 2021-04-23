/**
 * Author: justin0u0<mail@justin0u0.com.
 * Problem: https://leetcode.com/problems/network-delay-time/
 * Runtime: 188ms
 * Description: Floyd Whashall
 */

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));

    for (int i = 0; i < n; i++)
      dp[i][i] = 0;
    for (auto& edge: times) {
      dp[edge[0] - 1][edge[1] - 1] = edge[2];
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }

    int delayTime = -1;
    for (int i = 0; i < n; i++)
      delayTime = max(delayTime, dp[k - 1][i]);
    return delayTime == 0x3f3f3f3f ? -1 : delayTime;
  }
};


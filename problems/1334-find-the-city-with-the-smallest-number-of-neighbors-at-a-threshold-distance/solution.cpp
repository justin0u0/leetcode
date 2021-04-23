/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * Runtime: 28ms
 */

class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int** dp = new int*[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new int[n];
      memset(dp[i], 0x3f3f3f3f, sizeof dp[i]);
      dp[i][i] = 0;
    }

    for (auto& edge: edges) {
      dp[edge[0]][edge[1]] = edge[2];
      dp[edge[1]][edge[0]] = edge[2];
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int least = 0x3f3f3f3f;
    int foundCity;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++)
        if (dp[i][j] <= distanceThreshold)
          sum++;
      if (least >= sum) {
        least = sum;
        foundCity = i;
      }
    }
    return foundCity;
  }
};


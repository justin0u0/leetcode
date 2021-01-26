/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/freedom-trail/
 * Runtime: 116ms
 */

class Solution {
private:
  const int INF = 0x3f3f3f3f;
public:
  int findRotateSteps(string ring, string key) {
    const int rl = (int)ring.length();
    const int kl = (int)key.length();
    vector<vector<int>> dp(kl + 1, vector<int>(rl, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= kl; i++) {
      for (int j = 0; j < rl; j++) {
        if (key[i - 1] == ring[j]) {
          for (int k = 0; k < rl; k++) {
            // From k -> j
            int dist = abs(k - j);
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(dist, rl - dist) + 1);
          }
        }
      }
    }

    int steps = INF;
    for (int i = 0; i < rl; i++) {
      steps = min(steps, dp[kl][i]);
    }
    return steps;
  }
};


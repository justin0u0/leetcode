/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/freedom-trail/
 */

class Solution {
private:
  const int INF = 0x3f3f3f3f;
public:
  int findRotateSteps(string ring, string key) {
    const int ringLength = (int)ring.length();
    const int keyLength = (int)key.length();
    vector<vector<int>> dp(keyLength + 1, vector<int>(ringLength, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= keyLength; i++) {
      char target = key[i - 1];
      for (int j = 0; j < ringLength; j++) {
        if (target == ring[j]) {
          for (int k = 0; k < ringLength; k++) {
            // From k -> j
            int clockwise = (k - j + ringLength) % ringLength;
            int anticlockwise = (j - k + ringLength) % ringLength;
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(clockwise, anticlockwise) + 1);
          }
        }
      }
    }

    int steps = INF;
    for (int i = 0; i < ringLength; i++) {
      steps = min(steps, dp[keyLength][i]);
    }
    return steps;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/frog-jump/
 * Runtime: 200ms
 */

class Solution {
public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    if (stones.back() > n * (n - 1) / 2)
      return false;

    vector<vector<bool>> dp(n, vector<bool>(n + 1));
    dp[0][0] = true;

    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        int dist = stones[i] - stones[j];
        if (dist >= n) break;
        dp[i][dist] = dp[j][dist - 1] | dp[j][dist] | dp[j][dist + 1];
        if (i == n - 1 && dp[i][dist])
          return true;
      }
    }
    return false;
  }
};


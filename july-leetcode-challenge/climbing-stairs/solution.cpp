/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3407/
 */

class Solution {
public:
  int climbStairs(int n) {
    int dp[3] = {0};
    for (int i = 1; i <= n; i++) {
      dp[2] = dp[1] + dp[0];
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2];
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3405/
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = (int)prices.size();

    // 轉移：dp(i) = { max(a[i] - a[j] + dp(j - 2)) | j in [0 ~ i - 1] } or { dp(i - 1) }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (int j = 1; j < i; j++) {
        int value = prices[i - 1] - prices[j - 1];
        if (j >= 2) value += dp[j - 2];
        dp[i] = max(dp[i], value);
      }
    }
    return dp[n];
  }
};


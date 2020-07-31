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
    int best = -0x80000000;

    for (int i = 1; i <= n; i++) {
      dp[i] = max(dp[i - 1], prices[i - 1] + best);
      int value = -prices[i - 1];
      if (i >= 2) value += dp[i - 2];
      best = max(value, best);
    }
    return dp[n];
  }
};


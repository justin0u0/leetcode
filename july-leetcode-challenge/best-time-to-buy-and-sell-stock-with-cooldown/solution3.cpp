/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3405/
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int dp1 = 0; // dp(i)
    int dp2 = 0; // dp(i - 1)
    int dp3 = 0; // dp(i - 2)
    int best = -0x80000000;

    for (auto price: prices) {
      dp1 = max(dp2, price + best);
      best = max(-price + dp3, best);
      dp3 = dp2;
      dp2 = dp1;
    }
    return dp1;
  }
};


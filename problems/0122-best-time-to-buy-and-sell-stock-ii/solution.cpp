/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Runtime: 4ms
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profits = 0;
    for (int i = 1; i < prices.size(); i++)
      profits += max(prices[i] - prices[i - 1], 0);
    return profits;
  }
};


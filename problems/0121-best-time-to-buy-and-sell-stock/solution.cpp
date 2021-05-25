/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Runtime: 104ms
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int answer = 0;
    for (int& price : prices) {
      answer = max(answer, price - minPrice);
      minPrice = min(minPrice, price);
    }
    return answer;
  }
};


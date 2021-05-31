/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * Rumtime: 8ms
 * Time Complexity: O(NK)
 * Space Complexity: O(K)
 */

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    const int inf = 0x3f3f3f3f;
    vector<int> buy(k + 1, -inf);
    vector<int> sell(k + 1, -inf);

    for (int i = 0; i < n; i++) {
      buy[0] = max(buy[0], -prices[i]);
      sell[0] = 0;

      for (int j = k; j >= 1; j--) {
        buy[j] = max(buy[j], sell[j] - prices[i]);
        sell[j] = max(sell[j], buy[j - 1] + prices[i]);
      }
    }

    int answer = 0;
    for (int i = 1; i <= k; i++)
      answer = max(answer, sell[i]);
    return answer;
  }
};


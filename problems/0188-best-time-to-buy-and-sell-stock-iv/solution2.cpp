/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * Rumtime: 12ms
 * Time Complexity: O(NK)
 * Space Complexity: O(NK)
 */

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (!n) return 0;
    const int inf = 0x3f3f3f3f;
    vector<int> buy(k + 1);
    vector<int> sell(k + 1);

    buy[0] = -prices[0];
    sell[0] = 0;
    for (int i = 1; i < n; i++) {
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


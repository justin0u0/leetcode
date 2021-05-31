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
    vector<vector<int>> buy(n, vector<int>(k + 1, -inf));
    vector<vector<int>> sell(n, vector<int>(k + 1, -inf));

    buy[0][0] = -prices[0];
    sell[0][0] = 0;
    for (int i = 1; i < n; i++) {
      buy[i][0] = max(buy[i - 1][0], -prices[i]);
      sell[i][0] = 0;

      for (int j = 1; j <= k; j++) {
        buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
        sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        // cout << i << ' ' << j << ' ' << buy[i][j] << ' ' << sell[i][j] << endl;
      }
    }

    int answer = 0;
    for (int i = 1; i <= k; i++)
      answer = max(answer, sell[n - 1][i]);
    return answer;
  }
};


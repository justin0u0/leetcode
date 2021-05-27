/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * Runtime: 4ms
 * Description:
 *  dp(i): for profits[0:i], max profit with a sell at day i
 *    => dp(i)=prices[i]+max{dp(j)-prices[k]}, for all 0 < j < k-1 < k < i
 *    => observe that everytime i increase by 1,
 *        we got a new prices[k] (let says, k' equals to i-1),
 *        and it generates some {dp(j) - prices[k']},
 *        for all {dp(j)-prices[k']} generated by this prices[k'],
 *        max{dp(j)-prices[k']}=max{dp(j)}-prices[k'].
 *    => observe that everytime i increase by 1,
 *        we get a new dp(j) (let says, j' equals to i-3),
 *    => from above 2 observes, maintain `maxDp` for max{dp(j)}, so maxDp=max(maxDp, dp[i-3]);
 *        also, maintain `best` for max{dp(j)}-prices[k'], so best=max(best, maxDp - prices[i-1])
 *    => so, dp(i)=prices[i]+best
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n);

    const int inf = 0x3f3f3f3f;
    int maxDp = 0, best = -inf;
    for (int i = 0; i < n; i++) {
      if (i >= 3) maxDp = max(maxDp, dp[i - 3]);
      if (i >= 1) best = max(best, maxDp - prices[i - 1]);
      dp[i] = prices[i] + best;
    }
    for (int i = max(0, n - 3); i < n; i++)
      maxDp = max(maxDp, dp[i]);
    return maxDp;
  }
};


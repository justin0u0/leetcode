/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-divisible-subset/
 * Runtime: 32ms
 */

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    nums.emplace_back(1);
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n + 1, 0);
    vector<int> pre(n + 1, 0);
    dp[0] = 0;

    int maxValue = 0;
    int maxI;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            pre[i] = j;
          }
        }
      }

      if (maxValue < dp[i]) {
        maxValue = dp[i];
        maxI = i;
      }
    }

    vector<int> answer{nums[maxI]};
    while (pre[maxI]) {
      maxI = pre[maxI];
      answer.emplace_back(nums[maxI]);
    }
    return answer;
  }
};


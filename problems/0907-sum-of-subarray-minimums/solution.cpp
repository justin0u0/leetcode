/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Runtime: 76ms
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int sumSubarrayMins(vector<int>& arr) {
    stack<pair<int, int>> stk;

    int answer = 0;
    long long sum = 0;
    for (int value: arr) {
      int weight = 1;
      while (!stk.empty() && value < stk.top().first) {
        sum -= stk.top().first * stk.top().second;
        weight += stk.top().second;
        stk.pop();
      }
      stk.push({value, weight});
      sum += value * weight;
      answer = (answer + sum % mod) % mod;
    }
    return answer;
  }
};


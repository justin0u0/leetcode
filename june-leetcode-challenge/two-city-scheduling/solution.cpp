/*
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
 */

class Solution {
private:
  static bool compare(vector<int>& lhs, vector<int>& rhs) {
    return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
  }
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), compare);
    int totalCost = 0;
    for (int i = 0; i < (int)costs.size(); i++) {
      if (i < (int)costs.size() / 2) {
        totalCost += costs[i][0];
      } else {
        totalCost += costs[i][1];
      }
    }
    return totalCost;
  }
};


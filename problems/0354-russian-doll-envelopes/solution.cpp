/**
 * Author: justin0u0<mail@justin0iu0.com>
 * Problem: https://leetcode.com/problems/russian-doll-envelopes/
 * Runtime: 32ms
 */

class Solution {
private:
  static bool compare(const vector<int>& lhs, const vector<int>& rhs) {
    return (lhs[0] == rhs[0]) ? (lhs[1] > rhs[1]) : (lhs[0] < rhs[0]);
  }
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), compare);
    vector<int> lis{0};
    for (const vector<int>& envelope: envelopes) {
      if (envelope[1] > lis.back()) lis.emplace_back(envelope[1]);
      else *(lower_bound(lis.begin(), lis.end(), envelope[1])) = envelope[1];
    }
    return (int)lis.size() - 1;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/insert-interval/
 * Runtime: 52ms
 */

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    for (auto interval: intervals) {
      if (interval[0] <= newInterval[0] && newInterval[0] <= interval[1]) newInterval[0] = interval[0];
      if (interval[0] <= newInterval[1] && newInterval[1] <= interval[1]) newInterval[1] = interval[1];
    }
    vector<vector<int>> newIntervals{newInterval};
    for (auto interval: intervals) {
      if (!(newInterval[0] <= interval[0] && interval[1] <= newInterval[1])) {
        if (interval[1] < newInterval[0]) {
          newIntervals.back() = interval;
          newIntervals.emplace_back(newInterval);
        } else {
          newIntervals.emplace_back(interval);
        }
      }
    }
    return newIntervals;
  }
};


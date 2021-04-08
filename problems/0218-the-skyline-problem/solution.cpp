/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-skyline-problem/
 * Runtime: 28ms
 * Description: Line Sweep + Multiset
 */

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> lines;
    for (auto& building: buildings) {
      lines.emplace_back(building[0], building[2]);
      lines.emplace_back(building[1], -building[2]);
    }
    sort(lines.begin(), lines.end());
    multiset<int, greater<int>> s;
    vector<vector<int>> answer;
    int prevH = -1;
    for (auto& line: lines) {
      if (line.second > 0)
        s.insert(line.second);
      else
        s.erase(s.find(-line.second));
      int h = *s.begin();
      if (prevH != h && (&line == &lines.back() || line.first != next(&line)->first)) {
        prevH = h;
        answer.emplace_back(vector<int>{line.first, h});
      }
    }
    return answer;
  }
};


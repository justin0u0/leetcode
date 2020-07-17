/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
 */

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    set<pair<int, int>> box;

    int total = 0;
    for (int i = 0; i < n; i++) {
      ++total;
      if (i == n - 1 || nums[i] != nums[i + 1]) {
        box.insert(make_pair(total, nums[i]));
        if ((int)box.size() > k) box.erase(box.begin());
        total = 0;
      }
    }

    vector<int> answer;
    for (auto value: box) answer.emplace_back(value.second);
    return answer;
  }
};


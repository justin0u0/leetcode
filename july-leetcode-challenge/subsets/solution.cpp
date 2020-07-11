/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/
 */

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = (int)nums.size();
    vector<vector<int>> answer;

    for (int i = 0; i < (1 << n); i++) {
      vector<int> box;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) box.emplace_back(nums[j]);
      }
      answer.emplace_back(box);
    }
    return answer;
  }
};

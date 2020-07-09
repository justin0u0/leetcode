/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
 */

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = (int)nums.size();

    vector<vector<int>> solutions;
    for (int i = 0; i < n; i++) {
      int l = i + 1;
      int r = n - 1;

      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < 0) l++;
        else if (sum > 0) r--;
        else {
          vector<int> solution{nums[i], nums[l], nums[r]};
          solutions.emplace_back(solution);
          while (l < r && nums[l] == solution[1]) l++;
          while (l < r && nums[r] == solution[2]) r--;
        }
      }
      while (i + 1 < n && nums[i + 1] == nums[i]) i++;
    }
    return solutions;
  }
};


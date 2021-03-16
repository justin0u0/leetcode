/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * Runtime: 4ms
 */

class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums[0] < nums.back())
      return nums[0];

    int l = 0, r = (int)nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] == nums[r - 1])
        r--;
      else if (nums[mid] < nums[r - 1])
        r = mid;
      else
        l = mid + 1;
    }
    return nums[r];
  }
};


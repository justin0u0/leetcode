/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Runtime: 0ms
 */

class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums[0] <= nums.back())
      return nums[0];

    int l = 0, r = (int)nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      cout << l << ' ' << r << ' ' << mid << endl;
      if (nums[mid] < nums.back())
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }
};


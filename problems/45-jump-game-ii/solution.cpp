/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/jump-game-ii/
 * Runtime: 20ms
 */

class Solution {
public:
  int jump(vector<int>& nums) {
    int n = (int)nums.size();
    int steps = 0;
    int iL = 0, iR = 0;
    while (iR < n - 1) {
      int next_iR = 0;
      for (int i = iL; i <= iR; i++)
        next_iR = max(next_iR, i + nums[i]);
      iL = iR + 1;
      iR = next_iR;
      steps++;
    }
    return steps;
  }
};


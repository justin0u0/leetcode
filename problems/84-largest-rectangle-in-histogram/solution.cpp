/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Runtime: 20ms
 */

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = (int)heights.size();
    vector<int> left(n);
    vector<int> stk(n + 1);
    int idx = 0;
  
    for (int i = 0; i < n; i++) {
      while (idx && heights[stk[idx]] >= heights[i]) --idx;
      if (!idx) left[i] = i + 1;
      else left[i] = i - stk[idx];
      stk[++idx] = i;
    }
    idx = 0;

    int largestArea = 0;
    for (int i = n - 1; i >= 0; i--) {
      while (idx && heights[stk[idx]] >= heights[i]) --idx;

      int right;
      if (!idx) right = n - i;
      else right = stk[idx] - i;
      stk[++idx] = i;

      largestArea = max(largestArea, (right + left[i] - 1) * heights[i]);
    }
    return largestArea;
  }
};



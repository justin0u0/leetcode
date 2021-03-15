/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    heights.emplace_back(0);
    int n = (int)heights.size();
    stack<int> stk;

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && heights[i] < heights[stk.top()]) {
        int idx = stk.top();
        stk.pop();
        int width = (stk.empty()) ? i : (i - stk.top() - 1);
        maxArea = max(maxArea, heights[idx] * width);
      }
      stk.push(i);
    }
    return maxArea;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximal-rectangle/
 * Runtime: 60ms
 */

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();

    vector<int> heights(m);
    vector<int> left(m);
    vector<int> stk(m + 1);
    int maximal = 0;
    for (int i = 0; i < n; i++) {
      int idx = 0;
      for (int j = 0; j < m; j++) {
        if (i && matrix[i][j] == '1') {
          ++heights[j];
        } else {
          heights[j] = matrix[i][j] - '0';
        }

        while (idx && heights[stk[idx]] >= heights[j]) --idx;
        if (!idx) left[j] = j + 1;
        else left[j] = j - stk[idx];
        stk[++idx] = j;
      }

      idx = 0;
      for (int j = m - 1; j >= 0; j--) {
        while (idx && heights[stk[idx]] >= heights[j]) --idx;
        int right;
        if (!idx) right = m - j;
        else right = stk[idx] - j;
        stk[++idx] = j;

        maximal = max(maximal, (left[j] + right - 1) * heights[j]);
      }
    }
    return maximal;
  }
};


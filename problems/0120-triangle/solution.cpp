/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/triangle/
 * Runtime: 4ms
 * Space: O(1)
 */

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    for (int i = 1; i < n; i++) {
      triangle[i][0] += triangle[i - 1][0];
      triangle[i][i] += triangle[i - 1][i - 1];
      for (int j = 1; j < i; j++)
        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    }

    int answer = triangle[n - 1][0];
    for (int i = 1; i < n; i++)
      answer = min(answer, triangle[n - 1][i]);
    return answer;
  }
};


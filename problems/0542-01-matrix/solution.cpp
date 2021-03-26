/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/01-matrix/
 * Runtime: 64ms
 */

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!matrix[i][j])
          q.push({i, j});
        else
          matrix[i][j] = -1;
      }
    }

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};
    for (int nextDist = 1; !q.empty(); nextDist++) {
      int i = q.size();
      while (i--) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int j = 0; j < 4; j++) {
          int newx = x + dx[j];
          int newy = y + dy[j];
          if (newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[newx][newy] == -1) {
            matrix[newx][newy] = nextDist;
            q.push({newx, newy});
          }
        }
      }
    }
    return matrix;
  }
};


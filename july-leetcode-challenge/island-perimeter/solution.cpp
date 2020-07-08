/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/
 */

class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < (int)grid.size(); i++) {
      for (int j = 0; j < (int)grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          perimeter += 4;
          for (int k = 0; k < 4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];
            if (newx >= 0 && newy >= 0 && newx < (int)grid.size() && newy < (int)grid[i].size() && grid[newx][newy] == 1)
              --perimeter;
          }
        }
      }
    }
    return perimeter;
  }
};


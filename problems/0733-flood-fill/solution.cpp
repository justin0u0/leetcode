/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flood-fill/
 * Runtime: 4ms
 */

class Solution {
private:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  void dfs(vector<vector<int>>& image, int r, int c, int startColor, int newColor) {
    image[r][c] = newColor;
    for (int i = 0; i < 4; i++) {
      int newr = r + dx[i];
      int newc = c + dy[i];
      if (newr >= 0 && newr < image.size()
          && newc >= 0 && newc < image[0].size()
          && image[newr][newc] == startColor)
        dfs(image, newr, newc, startColor, newColor);
    }
  }
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] != newColor)
      dfs(image, sr, sc, image[sr][sc], newColor);
    return image;
  }
};


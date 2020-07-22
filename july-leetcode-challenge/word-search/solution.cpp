/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/
 */

class Solution {
private:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};
  int n, m;
  bool finder(vector<vector<char>>& board, int x, int y, char *s) {
    if ((*s) == '\0') return true;
    for (int i = 0; i < 4; i++) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx >= 0 && newy >= 0 && newx < n && newy < m && board[newx][newy] == (*s)) {
        board[newx][newy] = 0;
        if (finder(board, newx, newy, s + 1)) return true;
        board[newx][newy] = (*s);
      }
    }
    return false;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    n = (int)board.size();
    m = (int)board[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          board[i][j] = 0;
          if (finder(board, i, j, &word[1])) return true;
          board[i][j] = word[0];
        }
      }
    }
    return false;
  }
};


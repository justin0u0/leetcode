/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/surrounded-regions/
 * Runtime: 12ms
 */

class Solution {
private:
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};

  int n, m;

  // Flood fill 'O' -> '$'
  void dfs(vector<vector<char>>& board, int x, int y) {
    board[x][y] = '$';
    for (int i = 0; i < 4; i++) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx >= 0 && newx < n && newy >= 0 && newy < m && board[newx][newy])
        dfs(board, newx, newy);
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    n = (int)board.size();
    m = (int)board[0].size();
    for (int i = 0; i < n; i++) {
      if (board[i][0] == 'O')
        dfs(board, i, 0);;
      if (board[i][m - 1] == 'O')
        dfs(board, i, m - 1);
    }
    for (int i = 0; i < m; i++) {
      if (board[0][i] == 'O')
        dfs(board, 0, i);
      if (board[n - 1][i] == 'O')
        dfs(board, n - 1, i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '$')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};


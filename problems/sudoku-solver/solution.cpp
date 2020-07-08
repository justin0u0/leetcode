/**
 * Author: justin0u0<mail@justin0u0>
 * Problem: https://leetcode.com/problems/sudoku-solver/
 * Runtime: 28ms
 */

class Solution {
private:
  bool solver(int x, int y, vector<vector<char>>& board) {
    if (x == 9) return true;

    int nextX = y == 8 ? x + 1 : x;
    int nextY = y == 8 ? 0 : y + 1;
    if (board[x][y] == '.') {
      for (int i = 1; i <= 9; i++) {
        bool valid = true;
        char cell = i + '0';
        for (int j = 0; j < 9; j++) {
          int blockX = (x / 3) * 3 + (j / 3);
          int blockY = (y / 3) * 3 + (j % 3);
          if (board[x][j] == cell || board[j][y] == cell || board[blockX][blockY] == cell) {
            valid = false;
            break;
          }
        }
        if (!valid) continue;
        board[x][y] = cell;
        if (solver(nextX, nextY, board)) return true;
        board[x][y] = '.';
      }
    } else {
      return solver(nextX, nextY, board);
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    solver(0, 0, board);
  }
};


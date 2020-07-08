/**
 * Author: justin0u0<mail@justin0u0>
 * Problem: https://leetcode.com/problems/sudoku-solver/
 * Runtime: 8ms
 */

class Solution {
private:
  bool col[9][9], row[9][9], block[9][9];
  inline void toggleState(int x, int y, int i) {
    row[x][i] ^= true;
    col[y][i] ^= true;
    block[x / 3 * 3 + y / 3][i] ^= true;
  }
  bool solver(int x, int y, vector<vector<char>>& board) {
    if (x == 9) return true;

    int nextX = y == 8 ? x + 1 : x;
    int nextY = y == 8 ? 0 : y + 1;
    if (board[x][y] == '.') {
      for (int i = 0; i < 9; i++) {
        if (!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]) {
          board[x][y] = i + '1';
          toggleState(x, y, i);
          if (solver(nextX, nextY, board)) return true;
          toggleState(x, y, i);
          board[x][y] = '.';
        }
      }
    } else {
      return solver(nextX, nextY, board);
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    memset(col, false, sizeof col);
    memset(row, false, sizeof row);
    memset(block, false, sizeof block);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int cell = board[i][j] - '1';
          row[i][cell] = true;
          col[j][cell] = true;
          block[i / 3 * 3 + j / 3][cell] = true;
        }
      }
    }
    solver(0, 0, board);
  }
};


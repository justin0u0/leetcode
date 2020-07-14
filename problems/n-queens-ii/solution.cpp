/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-queens/
 * Runtime: 8ms
 */

class Solution {
private:
  int solutions = 0;
  void solver(vector<int>& col, int n) {
    int row = (int)col.size();
    if (row == n) {
      solutions++;
      return;
    }
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < row; j++) {
        if (col[j] == i || j + col[j] == row + i || j - col[j] == row - i) {
          ok = false;
          break;
        }
      }
      if (ok) {
        col.emplace_back(i);
        solver(col, n);
        col.pop_back();
      }
    }
  }
public:
  int totalNQueens(int n) {
    vector<int> col;
    solver(col, n);
    return solutions;
  }
};



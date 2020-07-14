/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-queens/
 * Runtime: 16ms
 */

class Solution {
private:
  vector<vector<string>> solutions;
  void solver(vector<int>& col, int n) {
    int row = (int)col.size();
    if (row == n) {
      vector<string> solution;
      for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++)
          s += (col[i] == j) ? 'Q' : '.';
        solution.emplace_back(s);
      }
      solutions.emplace_back(solution);
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
  vector<vector<string>> solveNQueens(int n) {
    vector<int> col;
    solver(col, n);
    return solutions;
  }
};



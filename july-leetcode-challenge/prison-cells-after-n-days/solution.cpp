/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/
 */

class Solution {
private:
  int getHash(vector<int>& cells) {
    int hashValue = 0;
    for (auto cell: cells) hashValue = (hashValue << 1) + cell;
    return hashValue;
  }
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> exists((1 << 8), -1);
    vector<vector<int>> cellsBox;

    int value = getHash(cells);
    while (exists[value] == -1) {
      exists[value] = (int)cellsBox.size();
      cellsBox.emplace_back(cells);

      vector<int> nextCells(8, 0);
      for (int i = 1; i < 7; i++) {
        nextCells[i] = !(cells[i - 1] ^ cells[i + 1]);
      }
      cells = nextCells;
      value = getHash(cells);
    }

    if (N < (int)cellsBox.size()) {
      return cellsBox[N];
    }

    int cycleSize = (int)cellsBox.size() - exists[value];
    N = (N - exists[value]) % cycleSize;
    return cellsBox[N + exists[value]];
  }
};


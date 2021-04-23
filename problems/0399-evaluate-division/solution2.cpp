/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/evaluate-division/
 * Runtime: 0ms
 * Description: Floyd Warshall
 */

class Helper {
private:
  int idx = 0;
  unordered_map<string, int> book;
public: 
  int getID(string& s) {
    return (!book[s]) ? (book[s] = ++idx) : book[s];
  }

  int maxID() {
    return idx;
  }
};

class Solution {
private:
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    Helper* h = new Helper();

    vector<vector<double>> dp(100, vector<double>(100, -1));
    int sz = equations.size();
    for (int i = 0; i < sz; i++) {
      int x = h->getID(equations[i][0]);
      int y = h->getID(equations[i][1]);
      dp[x][y] = values[i];
      dp[y][x] = 1 / values[i];
    }

    int n = h->maxID();
    for (int i = 1; i <= n; i++)
      dp[i][i] = 1;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (dp[i][j] == -1 && dp[i][k] != -1 && dp[k][j] != -1)
            dp[i][j] = dp[i][k] * dp[k][j];
        }
      }
    }

    vector<double> answers;
    for (auto& query: queries) {
      answers.emplace_back(dp[h->getID(query[0])][h->getID(query[1])]);
    }
    return answers;
  }
};


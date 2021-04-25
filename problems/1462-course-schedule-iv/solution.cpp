/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/course-schedule-iv/
 * Runtime: 400ms
 * Description: Floyd Warshall
 */

class Solution {
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (auto& prerequisite : prerequisites) {
      dp[prerequisite[0]][prerequisite[1]] = true;
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dp[i][j] = (dp[i][j] || (dp[i][k] && dp[k][j]));
    vector<bool> answers;
    for (auto& query : queries)
      answers.emplace_back(dp[query[0]][query[1]]);
    return answers;
  }
};


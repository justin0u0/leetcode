/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * Runtime: 240ms
 */

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<bool> hasInDegree(n);

    for (auto& edge : edges)
      hasInDegree[edge[1]] = true;
    vector<int> answer;
    for (int i = 0; i < n; i++)
      if (!hasInDegree[i])
        answer.emplace_back(i);
    return answer;
  }
};


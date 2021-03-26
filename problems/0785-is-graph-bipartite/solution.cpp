/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/is-graph-bipartite/
 * Runtime: 20ms
 */

class Solution {
private:
  bool dfs(int u, vector<vector<int>>& G, vector<int>& color) {
    for (int v: G[u]) {
      if (color[v] == color[u])
        return false;
      if (!color[v]) {
        color[v] = 3 - color[u];
        if (!dfs(v, G, color)) return false;
      }
    }
    return true;
  }
public:
  bool isBipartite(vector<vector<int>>& G) {
    int n = G.size();

    vector<int> color(n);
    for (int i = 0; i < n; i++) {
      if (!color[i]) {
        color[i] = 1;
        if (!dfs(i, G, color))
          return false;
      }
    }
    return true;
  }
};


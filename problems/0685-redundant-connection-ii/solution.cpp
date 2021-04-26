/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/redundant-connection-ii/
 * Runtime: 4ms
 */

class Solution {
private:
  int findSet(int* pa, int x) {
    return (!pa[x]) ? x : (pa[x] = findSet(pa, pa[x]));
  }
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();

    int *pa = new int[n + 1]();

    int *parent = new int[n + 1]();
    int e1 = -1, e2; // e1, e2 are edges that cause a node to have 2 in degree
    int e = -1; // e is the index of edge that cause a cycle last
    for (int i = 0; i < n; i++) {
      auto& edge = edges[i];
      if (parent[edge[1]]) {
        e1 = parent[edge[1]] - 1;
        e2 = i;
      } else {
        parent[edge[1]] = i + 1;

        // We skip adding e2
        int fx = findSet(pa, edge[0]);
        int fy = findSet(pa, edge[1]);
        if (fx != fy)
          pa[fx] = fy;
        else
          e = i;
      }
    }

    if (e1 == -1)
      return edges[e];
    if (e == -1)
      return edges[e2];
    return edges[e1];
  }
};


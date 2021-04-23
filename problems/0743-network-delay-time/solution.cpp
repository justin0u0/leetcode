/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/network-delay-time/
 * Runtime: 100ms
 * Description: Dijkstra
 */

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int s) {
    vector<vector<pair<int, int>>> G(n);
    for (auto& edge: times) {
      G[edge[0] - 1].emplace_back({edge[1] - 1, edge[2]});
    }

    --s;
    vector<int> d(n, 0x3f3f3f3f);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    int delayTime = -1;
    while (!pq.empty()) {
      int dist = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      if (d[u] < dist) continue;
      delayTime = max(delayTime, d[u]);
      --n;
      
      for (auto& edge: G[u]) {
        int v = edge.first;
        if (d[v] > d[u] + edge.second) {
          d[v] = d[u] + edge.second;
          pq.push({d[v], v});
        }
      }
    }

    return (!n) ? delayTime : -1;
  }
};


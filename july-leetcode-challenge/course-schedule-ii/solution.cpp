/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3394/
 */

class Solution {
private:
  vector<vector<int>> G;
  vector<bool> vis;
  vector<bool> instack;
  vector<int> courses;
  bool topological_sort(int u) {
    vis[u] = true;
    instack[u] = true;
    for (auto v: G[u]) {
      if (instack[v]) return false;
      else if (!vis[v] && !topological_sort(v)) return false;
    }
    instack[u] = false;
    courses.emplace_back(u);
    return true;
  }
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    G.resize(numCourses);
    vis.resize(numCourses, false);
    instack.resize(numCourses, false);
    for (auto prerequisite: prerequisites) {
      G[prerequisite[0]].emplace_back(prerequisite[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!vis[i] && !topological_sort(i)) {
        courses.clear();
        return courses;
      }
    }
    return courses;
  }
};


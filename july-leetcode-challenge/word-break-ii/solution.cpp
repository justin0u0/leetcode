/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/
 */

class Solution {
private:
  unordered_set<string> dict;
  vector<vector<int>> G;
  vector<bool> vis;
  vector<string> answer;

  bool buildGraph(int& n, string& s, int idx) {
    if (idx == n) return true;
    if (vis[idx]) return false;
    vis[idx] = true;

    string seg = "";
    bool findAnswer = false;
    for (int j = idx; j < n; j++) {
      seg += s[j];
      if (dict.find(seg) != dict.end()) {
        G[idx].emplace_back(j + 1);
        findAnswer |= buildGraph(n, s, j + 1);
      }
    }
    return findAnswer;
  }

  void findPath(int& n, string& s, int u, string cur) {
    if (u == n) {
      answer.emplace_back(cur);
      return;
    }

    if (u) cur += ' ';
    for (auto v: G[u]) {
      findPath(n, s, v, cur + s.substr(u, v - u));
    }
    if (u) cur.pop_back();
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    for (auto word: wordDict) dict.insert(word);
    int n = (int)s.length();
    G.resize(n);
    vis.resize(n);

    if (buildGraph(n, s, 0)) {
      cout << "Hello" << endl;
      findPath(n, s, 0, "");
    }
    return answer;
  }
};


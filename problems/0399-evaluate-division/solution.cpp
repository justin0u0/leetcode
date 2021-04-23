/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/evaluate-division/
 * Runtime: 0ms
 * Description: Union Find
 */

#define MAXN 100

class Helper {
private:
  int idx = 0;
  unordered_map<string, int> book;
public: 
  int getID(string& s) {
    return (!book[s]) ? (book[s] = ++idx) : book[s];
  }

  bool exist(string& s) {
    return !!book[s];
  }
};

class UnionFindSet {
private:
  vector<int> pa;
  vector<double> val;
public:
  UnionFindSet(int n) {
    pa.resize(n);
    val.resize(n, 1.0);
    for (int i = 0; i < n; i++)
      pa[i] = i;
  }

  int findSet(int x) {
    if (pa[x] == x)
      return pa[x];
    int fx = findSet(pa[x]);
    val[x] *= val[pa[x]];
    return (pa[x] = fx);
  }

  void mergeSet(int x, int y, double value) {
    int fx = findSet(x);
    int fy = findSet(y);
    val[fx] = val[y] / val[x] * value;
    pa[fx] = fy;
  }

  double solve(int x, int y) {
    return (findSet(x) != findSet(y)) ? -1 : val[x] / val[y];
  }
};

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    UnionFindSet* s = new UnionFindSet(100);
    Helper* h = new Helper();

    int sz = equations.size();
    for (int i = 0; i < sz; i++) {
      s->mergeSet(h->getID(equations[i][0]), h->getID(equations[i][1]), values[i]);
    }

    vector<double> answers;
    for (auto& query: queries) {
      if (!h->exist(query[0]) || !h->exist(query[1])) {
        answers.emplace_back(-1);
      } else {
        answers.emplace_back(s->solve(h->getID(query[0]), h->getID(query[1])));
      }
    }

    delete s;
    delete h;
    return answers;
  }
};


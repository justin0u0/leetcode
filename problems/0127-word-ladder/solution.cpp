/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-ladder/
 * Runtime: 472ms
 * Description: BFS
 */

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.emplace_back(beginWord);

    int n = wordList.size();
    int len = beginWord.length();

    queue<int> q;
    q.push(n - 1);
    vector<bool> used(n);
    used[n - 1] = true;

    for (int dist = 1; !q.empty(); dist++) {
      int todo = q.size();
      while (todo--) {
        const string& cur = wordList[q.front()];
        q.pop();

        if (cur == endWord)
          return dist;

        for (int i = 0; i < n; i++) {
          if (!used[i]) {
            int diffs = 0;
            for (int j = 0; diffs <= 1 && j < len; j++)
              if (cur[j] != wordList[i][j])
                diffs++;
            if (diffs == 1) {
              used[i] = true;
              q.push(i);
            }
          }
        }
      }
    }
    return 0;
  }
};


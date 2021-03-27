/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-ladder/
 * Runtime: 20ms
 * Description: Double-ended BFS
 */

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int len = beginWord.length();
    unordered_set<string> dict;
    for (string& word: wordList)
      dict.insert(word);
    if (dict.find(endWord) == dict.end())
      return 0;
    dict.erase(endWord);

    unordered_set<string> inUsed1, inUsed2;
    inUsed1.insert(beginWord);
    inUsed2.insert(endWord);

    queue<string> q1, q2;
    q1.push(beginWord);
    q2.push(endWord);

    for (int dist = 2; !q1.empty() || !q2.empty(); dist++) {
      bool turn1 = (q2.empty() || (!q1.empty() && q1.size() < q2.size()));
      queue<string>& q = turn1 ? q1 : q2;
      unordered_set<string>& used = turn1 ? inUsed1 : inUsed2;
      unordered_set<string>& inUsed = turn1 ? inUsed2 : inUsed1;

      int todo = q.size();
      while (todo--) {
        string cur = q.front();
        q.pop();

        for (int i = 0; i < len; i++) {
          char ch = cur[i];
          for (char j = 'a'; j <= 'z'; j++) {
            if (j == ch) continue;
            cur[i] = j;
            if (inUsed.find(cur) != inUsed.end())
              return dist;
            if (dict.find(cur) != dict.end()) {
              dict.erase(cur);
              used.insert(cur);
              q.push(cur);
            }
          }
          cur[i] = ch;
        }
      }
    }
    return 0;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-window-substring/
 * Runtime: 16ms
 */

class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> dict(128);
    for (auto ch: t) dict[ch]++;
    int total = 0;
    for (auto value: dict) {
      if (value > 0) total++;
    }

    int l = 0;
    int answerL, answerLen = 0x3f3f3f3f;
    for (int i = 0; i < (int)s.length(); i++) {
      if (--dict[s[i]] == 0) total--;
      while (!total) {
        if (i - l + 1 < answerLen) {
          answerL = l;
          answerLen = i - l + 1;
        }
        if (++dict[s[l++]] == 1) total++;
      }
    }
    if (answerLen == 0x3f3f3f3f)
      return "";
    else
      return s.substr(answerL, answerLen);
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * Runtime: 52ms
 */

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> indices;
    int sl = (int)s.length();
    if (!sl || words.empty()) return indices;
    int wl = (int)words[0].length();
    if (sl < wl * (int)words.size() || !wl) return indices;

    unordered_multiset<string> dict;
    for (auto word: words) dict.insert(word);

    for (int i = 0; i < wl; i++) {
      int left = i;
      for (int j = i; j + wl <= sl; j += wl) {
        string substring = s.substr(j, wl);
        while (left < j && dict.find(substring) == dict.end()) {
          dict.insert(s.substr(left, wl));
          left += wl;
        }
        auto it = dict.find(substring);
        if (it != dict.end()) {
          dict.erase(it);
          if (dict.empty()) indices.emplace_back(left);
        } else {
          left = j + wl;
        }
      }
      while (left + wl <= sl) {
        dict.insert(s.substr(left, wl));
        left += wl;
      }
    }
    return indices;
  }
};


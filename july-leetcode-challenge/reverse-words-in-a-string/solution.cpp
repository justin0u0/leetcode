/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/
 */

class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;

    const char *ch = s.c_str();
    while ((*ch) != '\0') {
      while ((*ch) != '\0' && (*ch) == ' ') ch++;
      string word = "";
      while ((*ch) != '\0' && (*ch) != ' ') {
        word += (*ch);
        ch++;
      }
      if (word != "") words.emplace_back(word);
    }

    reverse(words.begin(), words.end());
    string answer = "";
    if (!words.empty()) {
      answer += words[0];
      for (int i = 1; i < (int)words.size(); i++)
        answer += " " + words[i];
    }
    return answer;
  }
};


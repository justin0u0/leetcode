/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/text-justification/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = (int)words.size();
    vector<string> answer;

    for (int i = 0; i < n; ) {
      int width = (int)words[i].length();
      int j = i + 1;
      while (j < n && width + 1 + (int)words[j].length() <= maxWidth) {
        width += 1 + (int)words[j].length();
        j++;
      }

      string s = words[i];
      if (j != i + 1 && j != n) {
        int spaces = (maxWidth - width) / (j - i - 1);
        int extraSpaces = (maxWidth - width) % (j - i - 1);
        for (int k = i + 1; k < j; k++)
          s += string(spaces+ 1 + (k - (i + 1) < extraSpaces), ' ') + words[k];
      } else {
        for (int k = i + 1; k < j; k++) s += " " + words[k];
        s += string(maxWidth - (int)s.length(), ' ');
      }
      answer.emplace_back(s);
      i = j;
    }
    return answer;
  }
};


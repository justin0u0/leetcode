/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-palindromic-substring/
 * Runtime: 4ms
 */

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    int m = n * 2 + 1;

    char* ss = new char[m];
    for (int i = 0; i < n; i++) {
      ss[i << 1] = '#';
      ss[(i << 1) + 1] = s[i];
    }
    ss[m - 1] = '#';

    int* radius = new int[m]();
    int maxR = 0, center = 0;

    int maxRadius = 0, idx = 0;
    for (int i = 1; i < m; i++) {
      int j = center - (i - center);

      if (maxR >= i) {
        radius[i] = min(radius[j], j - (center - radius[center]));
      }
      if (maxR < i || j - radius[j] == 0 || i + radius[i] >= maxR) {
        while (i - radius[i] >= 0 && i + radius[i] < m && ss[i - radius[i]] == ss[i + radius[i]])
          radius[i]++;
        radius[i]--;
      }
      if (i + radius[i] > maxR) {
        maxR = i + radius[i];
        center = i;
      }
      if (radius[i] > maxRadius) {
        maxRadius = radius[i];
        idx = i;
      }
    }
    
    string answer = "";
    for (int i = idx - maxRadius; i <= idx + maxRadius; i++)
      if (ss[i] != '#')
        answer += ss[i];
    return answer;
  }
};


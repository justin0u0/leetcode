/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3404/
 */

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26);
    vector<int> cooldown(26);
    for (auto task: tasks) cnt[task - 'A']++;

    int all = (int)tasks.size();
    int answer = 0;
    while (all--) {
      int maxValue = 0, idx;
      for (int i = 0; i < 26; i++) {
        if (!cooldown[i] && cnt[i] > maxValue) {
          maxValue = cnt[i];
          idx = i;
        }
        if (cooldown[i]) --cooldown[i];
      }

      ++answer;
      if (!maxValue) {
        ++all;
      } else {
        --cnt[idx];
        cooldown[idx] = n;
      }
    }
    return answer;
  }
};


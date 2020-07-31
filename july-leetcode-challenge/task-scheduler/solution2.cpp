/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3404/
 */

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26);
    for (auto task: tasks) ++cnt[task - 'A'];
    sort(cnt.begin(), cnt.end());
    int idle = (cnt[25] - 1) * n;
    for (int i = 0; i < 25; i++) idle -= min(cnt[i], cnt[25] - 1);
    return (int)tasks.size() + max(0, idle);
  }
};


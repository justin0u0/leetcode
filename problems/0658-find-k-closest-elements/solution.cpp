/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-k-closest-elements/
 * Runtime: 44ms
 */

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = (int)arr.size();
    int l = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    int r = l + 1;
    while (k--) {
      if (r == n || (l >= 0 && abs(arr[l] - x) <= abs(arr[r] - x))) --l;
      else ++r;
    }
    vector<int> answer(arr.begin() + l + 1, arr.begin() + r);
    return answer;
  }
};


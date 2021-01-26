/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/permutation-sequence/
 * Runtime: 0ms
 */

class Solution {
public:
  string getPermutation(int n, int k) {
    int* arr = new int[n + 1];
    int* fact = new int[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      arr[i] = i;
      fact[i] = fact[i - 1] * i;
    }

    string ans = "";
    for (int i = n; i >= 1; i--) {
      int cnt = (k - 1) / fact[i - 1];
      for (int j = 1; j <= n; j++) {
        if (arr[j] > 0) {
          --cnt;
        }

        if (cnt < 0) {
          ans += (arr[j] + '0');
          k = (k - 1) % fact[i - 1] + 1;
          arr[j] = 0;
          break;
        }
      }
    }
    delete[] arr;
    return ans;
  }
};


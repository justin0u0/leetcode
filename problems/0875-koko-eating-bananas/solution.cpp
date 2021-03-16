/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/koko-eating-bananas/
 * Runtime: 36ms
 */

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int minK = 1, maxK = 1e9 + 10;
    while (minK < maxK) {
      int k = (minK + maxK) / 2;

      int sum = 0;
      for (int pile: piles)
        sum += (pile - 1) / k;
      if (sum <= h) maxK = k;
      else minK = k + 1;
    }
    return maxK;
  }
};


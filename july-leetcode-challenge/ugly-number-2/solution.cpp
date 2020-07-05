/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/
 */

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> box{1};
    int idx2 = 0;
    int idx3 = 0;
    int idx5 = 0;
    while ((int)box.size() < n) {
      int value2 = box[idx2] * 2;
      int value3 = box[idx3] * 3;
      int value5 = box[idx5] * 5;
      int minValue = min(value2, min(value3, value5));
      if (value2 == minValue) idx2++;
      if (value3 == minValue) idx3++;
      if (value5 == minValue) idx5++;
      box.emplace_back(minValue);
    }
    return box.back();
  }
};


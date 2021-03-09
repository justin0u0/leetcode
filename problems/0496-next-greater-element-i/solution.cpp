/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/next-greater-element-i/
 * Runtime: 8ms
 */

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = (int)nums1.size();
    int m = (int)nums2.size();
    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++)
      mapping.insert({nums1[i], i});

    vector<int> answer(n);
    vector<int> stk(m + 1, -1);
    int top = 0;
    for (int i = m - 1; i >= 0; i--) {
      while (top && nums2[i] > stk[top]) top--;
      if (mapping.find(nums2[i]) != mapping.end())
        answer[mapping[nums2[i]]] = stk[top];
      stk[++top] = nums2[i];
    }
    return answer;
  }
};


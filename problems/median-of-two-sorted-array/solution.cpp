/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

class Solution {
  int findKthNumber(int *arr1, int *arr2, int m, int n, int k) {
    if (m == 0) {
      return arr2[k - 1];
    }
    if (n == 0) {
      return arr1[k - 1];
    }
    if (k == 1) {
      return arr1[0] < arr2[0] ? arr1[0] : arr2[0];
    }

    int i = min(k / 2, m);
    int j = min(k / 2, n);
    if (arr1[i - 1] < arr2[j - 1]) {
      return findKthNumber(arr1 + i, arr2, m - i, n, k - i);
    } else {
      return findKthNumber(arr1, arr2 + j, m, n - j, k - j);
    }
  }
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    int k = (n + m) / 2 + 1;
    if ((n + m) & 1) {
      return findKthNumber(nums1.data(), nums2.data(), m, n, k);
    }
    return (findKthNumber(nums1.data(), nums2.data(), m, n, k) + findKthNumber(nums1.data(), nums2.data(), m, n, k - 1)) / 2.0;
  }
};


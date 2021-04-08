/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-query-mutable/
 * Runtime: 372ms
 * Description: Binary Indexed Tree - Update O(logN)
 */

class NumArray {
private:
  const int base = 2;
  int n;
  int* arr;
  int* bit;

  inline int lowbit(int x) {
    return x & -x;
  }

  void add(int x, int val) {
    for (int i = x; i < n + base; i += lowbit(i))
      bit[i] += val;
  }

  int sum(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      res += bit[i];
    return res;
  }
public:
  NumArray(vector<int>& nums) {
    n = (int)nums.size();
    arr = nums.data();
    bit = new int[n + base]();
    for (int i = 0; i < n; i++)
      add(i + base, nums[i]);
  }
  
  void update(int index, int val) {
    add(index + base, val - arr[index]);
    arr[index] = val;
  }
  
  int sumRange(int left, int right) {
    return sum(right + base) - sum(left + base - 1);
  }
};


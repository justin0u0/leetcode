/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-query-mutable/
 * Runtime: 380ms
 * Description: Segment Tree
 */

class NumArray {
private:
  int n;
  int* arr = nullptr;
  int* sum = nullptr;

  void build(int l, int r, int o) {
    if (l == r) {
      sum[o] = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, o * 2);
    build(mid + 1, r, o * 2 + 1);
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
  }

  void update(int l, int r, int o, int index, int val) {
    if (l == r) {
      sum[o] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (index <= mid)
      update(l, mid, o * 2, index, val);
    else
      update(mid + 1, r, o * 2 + 1, index, val);
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
  }

  int query(int l, int r, int o, int left, int right) {
    if (left <= l && r <= right)
      return sum[o];
    int res = 0;
    int mid = (l + r) / 2;
    if (left <= mid)
      res += query(l, mid, o * 2, left, right);
    if (right > mid)
      res += query(mid + 1, r, o * 2 + 1, left, right);
    return res;
  }
public:
  NumArray(vector<int>& nums) {
    n = nums.size();
    arr = nums.data();
    sum = new int[n * 4];
    build(0, n - 1, 1);
  }
  
  void update(int index, int val) {
    update(0, n - 1, 1, index, val);
  }
  
  int sumRange(int left, int right) {
    return query(0, n - 1, 1, left, right);
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-query-mutable/
 * Runtime: 360ms
 * Description: Iterative Segment Tree
 */

class NumArray {
private:
  int n = 1;
  int* sum;
public:
  NumArray(vector<int>& nums) {
    int sz = nums.size();

    // build
    while (n < sz) n <<= 1;
    sum = new int[n << 1];
    memset(sum, 0, sizeof sum);
    for (int i = n; i < n + sz; i++)
      sum[i] = nums[i - n];
    for (int i = n - 1; i > 0; i--)
      sum[i] = sum[i << 1] + sum[i << 1 | 1];
  }
  
  void update(int index, int val) {
    index += n;
    sum[index] = val;
    for (; index > 0; index >>= 1)
      sum[index >> 1] = sum[index] + sum[index ^ 1];
  }
  
  int sumRange(int left, int right) {
    int ans = 0;
    for (int l = left + n, r = right + n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans += sum[l++];
      if (!(r & 1)) ans += sum[r--];
    }
    return ans;
  }
};


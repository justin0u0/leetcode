/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists/
 * Runtime: 28ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
  ListNode* inplaceMerge(ListNode* lhs, ListNode* rhs) {
    if (!lhs) return rhs;
    if (!rhs) return lhs;

    if (lhs->val < rhs->val) {
      lhs->next = inplaceMerge(lhs->next, rhs);
      return lhs;
    } else {
      rhs->next = inplaceMerge(lhs, rhs->next);
      return rhs;
    }
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int listsLength = (int)lists.size();
    for (int i = 1; i < listsLength; i <<= 1) {
      for (int j = 0; j + i < listsLength; j += i * 2) {
        lists[j] = inplaceMerge(lists[j], lists[j + i]);
      }
    }
    return lists[0];
  }
};


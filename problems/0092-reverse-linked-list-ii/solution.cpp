/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-linked-list-ii/submissions/
 * Runtime: 0ms
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
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* preHead = new ListNode(0, head);
    ListNode* pre = preHead;
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    ListNode* cur = pre->next;
    for (int i = left; i < right; i++) {
      ListNode* temp = cur->next->next;
      cur->next->next = pre->next;
      pre->next = cur->next;
      cur->next = temp;
    }
    return preHead->next;
  }
};


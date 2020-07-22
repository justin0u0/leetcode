/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* node = head;
    while (node != nullptr) {
      if (node->next != nullptr && node->next->val == val) {
        node->next = node->next->next;
      } else {
        node = node->next;
      }
    }
    if (head != nullptr && head->val == val)
      return head->next;
    return head;
  }
};


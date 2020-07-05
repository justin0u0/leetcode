/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
  ListNode* reverseSingleGroup(ListNode* head, ListNode* lastNode, int k) {
    if (k == 0) return lastNode;
    ListNode* newHead = reverseSingleGroup(head->next, head, k - 1);
    head->next = lastNode;
    return newHead;
  }
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    for (int i = 1; i < k && node != nullptr; i++)
      node = node->next;
    if (node == nullptr)
      return head;
    ListNode* newHead = reverseKGroup(node->next, k);
    return reverseSingleGroup(head, newHead, k);
  }
};


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
    ListNode* nextNode = head->next;
    head->next = lastNode;
    if (k == 1) return head;
    return reverseSingleGroup(nextNode, head, k - 1);
  }
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    for (int i = 1; i < k && node != nullptr; i++)
      node = node->next;
    if (node == nullptr)
      return head;
    return reverseSingleGroup(head, reverseKGroup(node->next, k), k);
  }
};


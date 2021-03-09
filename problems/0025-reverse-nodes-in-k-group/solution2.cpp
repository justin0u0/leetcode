/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Runtime: 12ms
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* preHead = new ListNode(0);
    preHead->next = head;

    int len = 0;
    while (head != nullptr) {
      head = head->next;
      len++;
    }

    ListNode* pre = preHead;
    ListNode* cur = pre->next;
    for (int i = 0; i < len / k; i++) {
      for (int j = 0; j < k - 1; j++) {
        ListNode* temp = cur->next->next;
        cur->next->next = pre->next;
        pre->next = cur->next;
        cur->next = temp;
      }
      pre = cur;
      cur = cur->next;
    }
    return preHead->next;
  }
};


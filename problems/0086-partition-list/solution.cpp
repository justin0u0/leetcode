/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-list/
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* big = new ListNode(0);

    ListNode* smallHead = small;
    ListNode* bigHead = big;
    while (head != nullptr) {
      if (head->val >= x) {
        big->next = head;
        big = big->next;
      } else {
        small->next = head;
        small = small->next;
      }
      head = head->next;
    }
    small->next = bigHead->next;
    big->next = nullptr;
    return smallHead->next;
  }
};


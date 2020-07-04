/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists/
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
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  void insertBack(int value) {
    if (head == nullptr) {
      head = new ListNode(value);
      tail = head;
    } else {
      ListNode* newNode = new ListNode(value);
      tail->next = newNode;
      tail = tail->next;
    }
  }
  ListNode* merge2Lists(ListNode* lhs, ListNode* rhs) {
    head = nullptr;
    tail = nullptr;
    while (lhs != nullptr || rhs != nullptr) {
      if (rhs == nullptr || (lhs != nullptr && lhs->val < rhs->val)) {
        insertBack(lhs->val);
        lhs = lhs->next;
      } else {
        insertBack(rhs->val);
        rhs = rhs->next;
      }
    }
    return head;
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    while ((int)lists.size() > 1) {
      vector<ListNode*> newLists;
      for (int i = 0; i < (int)lists.size() - 1; i += 2) {
        ListNode* mergedList = merge2Lists(lists[i], lists[i + 1]);
        newLists.emplace_back(mergedList);
      }
      if ((int)lists.size() & 1) {
        newLists.emplace_back(lists.back());
      }
      lists = newLists;
    }
    return lists[0];
  }
};


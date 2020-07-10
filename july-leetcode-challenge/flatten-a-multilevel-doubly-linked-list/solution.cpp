/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node* flatten(Node* head) {
    Node* node = head;
    stack<Node*> stk;
    while (node != nullptr) {
      if (node->child != nullptr) {
        stk.push(node->next);
        node->next = node->child;
        node->child->prev = node;
        node->child = nullptr;
      } else if (node->next == nullptr && !stk.empty()) {
        node->next = stk.top();
        if (stk.top() != nullptr) {
          stk.top()->prev = node;
        }
        stk.pop();
      }
      node = node->next;
    }
    return head;
  }
};


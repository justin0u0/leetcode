/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/recover-binary-search-tree/
 * Runtime: 32ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* lastNode = nullptr;
  TreeNode* target = nullptr;
  TreeNode* candidate = nullptr;

  void solver(TreeNode* root) {
    if (root == nullptr)
      return;

    solver(root->left);

    if (target == nullptr && (lastNode != nullptr && lastNode->val > root->val)) {
      target = lastNode;
      candidate = root;
    } else if (target != nullptr && (lastNode != nullptr && lastNode->val > root->val)) {
      candidate = root;
    }
    lastNode = root;

    solver(root->right);
  }

  void recoverTree(TreeNode* root) {
    solver(root);
    swap(target->val, candidate->val);
  }
};


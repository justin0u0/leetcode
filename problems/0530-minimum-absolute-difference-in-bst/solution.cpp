/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * Runtime: 16ms
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
private:
  TreeNode* prevNode = nullptr;
public:
  int getMinimumDifference(TreeNode* root) {
    int difference = 0x7fffffff;
    if (root->left != nullptr)
      difference = min(difference, getMinimumDifference(root->left));
    if (prevNode != nullptr)
      difference = min(difference, root->val - prevNode->val);
    prevNode = root;
    if (root->right != nullptr)
      difference = min(difference, getMinimumDifference(root->right));
    return difference;
  }
};


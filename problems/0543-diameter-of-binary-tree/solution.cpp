/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/diameter-of-binary-tree/
 * Runtime: 8ms
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
  int diameter = 0;
  int dfs(TreeNode* root) {
    if (root == nullptr)
      return 0;
    int leftHeight = dfs(root->left);
    int rightHeight = dfs(root->right);
    diameter = max(diameter, rightHeight + leftHeight);
    return max(leftHeight, rightHeight) + 1;
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return diameter;
  }
};


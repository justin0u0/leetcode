/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3347/
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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    invertTree(root->left);
    invertTree(root->right);
    
    TreeNode* leftChild = root->left;
    TreeNode* rightChild = root->right;
    root->left = rightChild;
    root->right = leftChild;
    return root;
  }
};

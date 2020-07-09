/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/
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
  int widthOfBinaryTree(TreeNode* root) {
    vector<TreeNode*> box[2];
    bool level = 0;
    if (root != nullptr) {
      root->val = 1;
      box[level].emplace_back(root);
    }

    int maxWidth = 0;
    while (!box[level].empty()) {
      bool nextLevel = level ^ 1;
      int minValue = box[level][0]->val;
      int maxValue = box[level].back()->val;
      for (auto node: box[level]) {
        if (node->left != nullptr) {
          node->left->val = (node->val - minValue + 1) * 2 - 1;
          box[nextLevel].emplace_back(node->left);
        }
        if (node->right != nullptr) {
          node->right->val = (node->val - minValue + 1) * 2;
          box[nextLevel].emplace_back(node->right);
        }
      }
      box[level].clear();
      level = nextLevel;
      maxWidth = max(maxWidth, maxValue - minValue + 1);
    }
    return maxWidth;
  }
};


/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    if (root == nullptr) return answer;

    vector<TreeNode*> level[2];
    bool cur = false;
    level[cur].emplace_back(root);
    while (!level[cur].empty()) {
      vector<int> box;
      for (auto node: level[cur]) {
        box.emplace_back(node->val);
        if (cur && node->left != nullptr)
          level[cur ^ 1].emplace_back(node->left);
        if (node->right != nullptr)
          level[cur ^ 1].emplace_back(node->right);
        if (!cur && node->left != nullptr)
          level[cur ^ 1].emplace_back(node->left);
      }

      answer.emplace_back(box);
      level[cur].clear();
      cur ^= 1;
      reverse(level[cur].begin(), level[cur].end());
    }
    return answer;
  }
};


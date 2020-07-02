/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/
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
  void dfs(TreeNode* root, int level, vector<vector<int>>& box) {
    if (root == nullptr) return;
    if ((int)box.size() <= level) {
      vector<int> newBox{ root->val };
      box.emplace_back(newBox);
    } else {
      box[level].emplace_back(root->val);
    }
    dfs(root->left, level + 1, box);
    dfs(root->right, level + 1, box);
  }
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> box;
    dfs(root, 0, box);
    reverse(box.begin(), box.end());
    return box;
  }
};


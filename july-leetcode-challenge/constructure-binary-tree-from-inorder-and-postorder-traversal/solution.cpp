/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/
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
  unordered_map<int, int> pos;
  int idx;
  TreeNode* solver(vector<int>& inorder, vector<int>& postorder, int l, int r) {
    if (idx < 0) return nullptr;
    TreeNode* node = new TreeNode(postorder[idx]);
    if (pos[postorder[idx]] < l || pos[postorder[idx]] > r) return nullptr;
    idx--;
    node->right = solver(inorder, postorder, pos[postorder[idx + 1]] + 1, r);
    node->left = solver(inorder, postorder, l, pos[postorder[idx + 1]] - 1);
    return node;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = (int)inorder.size();
    if (!n) return nullptr;

    for (int i = 0; i < n; i++)
      pos[inorder[i]] = i;
    idx = n - 1;
    return solver(inorder, postorder, 0, n - 1);
  }
};


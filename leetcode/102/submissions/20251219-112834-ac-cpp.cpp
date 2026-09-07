/*
 * 102. Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 32.1%)
 * Memory: 17.2 MB (beats 45.4%)
 * Submitted: 2025-12-19 11:28:34 UTC
 * URL: https://leetcode.com/submissions/detail/1859728773/
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            level = {};

            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(level);
        }

        return res;
    }
};


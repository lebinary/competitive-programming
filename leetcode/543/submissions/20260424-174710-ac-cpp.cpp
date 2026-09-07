/*
 * 543. Diameter of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 23.7 MB (beats 72.5%)
 * Submitted: 2026-04-24 17:47:10 UTC
 * URL: https://leetcode.com/submissions/detail/1987198635/
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
    int diameter;
    
    int diameterOfBinaryTree(TreeNode *root) {
        this->diameter = 0;
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int leftHeight = dfs(root->left), rightHeight = dfs(root->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};

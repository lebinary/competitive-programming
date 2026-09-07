/*
 * 543. Diameter of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 23.7 MB (beats 41.7%)
 * Submitted: 2025-12-20 08:33:57 UTC
 * URL: https://leetcode.com/submissions/detail/1860417080/
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
    int best;
    int diameterOfBinaryTree(TreeNode *root) {
        this->best = 0;
        dfs(root);
        return best;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int leftHeight = dfs(root->left), rightHeight = dfs(root->right);
        best = max(best, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};

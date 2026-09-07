/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 26 ms (beats 29.6%)
 * Memory: 23.4 MB (beats 91.3%)
 * Submitted: 2025-10-07 10:14:06 UTC
 * URL: https://leetcode.com/submissions/detail/1794067817/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};


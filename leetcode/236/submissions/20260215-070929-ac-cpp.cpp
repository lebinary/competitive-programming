/*
 * 236. Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 746 ms (beats 5.1%)
 * Memory: 17.4 MB (beats 100.0%)
 * Submitted: 2026-02-15 07:09:30 UTC
 * URL: https://leetcode.com/submissions/detail/1919813782/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(count(root->left, p, q) == 2) return lowestCommonAncestor(root->left, p, q);
        if(count(root->right, p, q) == 2) return lowestCommonAncestor(root->right, p, q);
        return root;
    }

    int count(TreeNode* node, TreeNode* p, TreeNode*q) {
        if(node == nullptr) return 0;
        int res = node == p || node == q; 
        res += count(node->left, p, q);
        res += count(node->right, p, q);
        return res;
    }
};

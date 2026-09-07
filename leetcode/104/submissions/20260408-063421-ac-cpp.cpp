/*
 * 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 7.3%)
 * Memory: 19 MB (beats 99.9%)
 * Submitted: 2026-04-08 06:34:22 UTC
 * URL: https://leetcode.com/submissions/detail/1972303105/
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

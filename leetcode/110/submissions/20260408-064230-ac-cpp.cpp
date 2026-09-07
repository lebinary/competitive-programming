/*
 * 110. Balanced Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.8 MB (beats 98.2%)
 * Submitted: 2026-04-08 06:42:31 UTC
 * URL: https://leetcode.com/submissions/detail/1972310164/
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
    bool isBalanced(TreeNode* root) {
        auto [depth, balance] = dfs(root);
        return balance;
    }

    pair<int, bool> dfs(TreeNode* node) {
        if(!node) return {0, true};

        auto [leftDepth, leftBalance] = dfs(node->left);
        auto [rightDepth, rightBalance] = dfs(node->right);

        int depth = 1 + max(leftDepth, rightDepth);

        if(!leftBalance || !rightBalance) return {depth, false};
        if(abs(leftDepth - rightDepth) > 1) return {depth, false};

        return {depth, true};
    }
};

/**
Condition to maintain:
- Both subtrees need to be balanced
- |depth left - depth right| <= 1

**/

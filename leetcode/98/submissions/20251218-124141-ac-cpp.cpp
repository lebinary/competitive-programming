/*
 * 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 21.9 MB (beats 44.6%)
 * Submitted: 2025-12-18 12:41:42 UTC
 * URL: https://leetcode.com/submissions/detail/1858911121/
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
    bool isValidBST(TreeNode *root) { return valid(root, LLONG_MIN, LLONG_MAX); }

    bool valid(TreeNode *node, long long maxLeft, long long minRight) {
        if (node == nullptr) return true;
        if (maxLeft >= node->val || minRight <= node->val) return false;
        return valid(node->left, maxLeft, node->val) && valid(node->right, node->val, minRight);
    }
};


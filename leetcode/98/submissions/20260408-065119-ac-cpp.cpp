/*
 * 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22 MB (beats 44.6%)
 * Submitted: 2026-04-08 06:51:19 UTC
 * URL: https://leetcode.com/submissions/detail/1972317738/
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
    bool isValidBST(TreeNode *root) {
        return preorder(root, LLONG_MIN, LLONG_MAX);
    }

    bool preorder(TreeNode* node, long long lo, long long hi) {
        if(!node) return true;
        
        if(node->val <= lo || node->val >= hi) return false;

        return preorder(node->left, lo, node->val) && preorder(node->right, node->val, hi);
    }
};

/**
**/

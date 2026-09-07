/*
 * 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 21.8 MB (beats 74.7%)
 * Submitted: 2026-03-08 10:09:58 UTC
 * URL: https://leetcode.com/submissions/detail/1941833386/
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
        return preorder(root->left, LLONG_MIN, root->val) && preorder(root->right, root->val, LLONG_MAX);
    }

    bool preorder(TreeNode* node, long long min, long long  max) {
        if(!node) return true;
        if(node->val <= min || node->val >= max) return false;
        return preorder(node->left, min, node->val) && preorder(node->right, node->val, max);
    }
};

/**
preorder traverse with extra (min, max) paramters

preorder(node, min, max):
    if not node: return true

    if node.left && !(min > node.left < node): return false
    if node.right && !(node > node.right < max): return false

    return preorder(node.left, min, node.left) && preorder(node.right, node.right, max)
**/

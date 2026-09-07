/*
 * 114. Flatten Binary Tree to Linked List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17.5 MB (beats 52.6%)
 * Submitted: 2026-01-01 11:27:46 UTC
 * URL: https://leetcode.com/submissions/detail/1870946775/
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
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left == nullptr) return;
        if (root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
        } else {
            TreeNode *curr = root->left;
            TreeNode *prev = nullptr;
            while (curr != nullptr) {
                prev = curr;
                curr = curr->right;
            }

            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};


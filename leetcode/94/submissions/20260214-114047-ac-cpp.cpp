/*
 * 94. Binary Tree Inorder Traversal
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11 MB (beats 13.3%)
 * Submitted: 2026-02-14 11:40:47 UTC
 * URL: https://leetcode.com/submissions/detail/1918859130/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }

    void inorder(vector<int> &res, TreeNode* node) {
        if(node == nullptr) return;
        
        inorder(res, node->left);
        res.push_back(node->val);
        inorder(res, node->right);
    } 
};

/*
 * 938. Range Sum of BST
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 64.8 MB (beats 92.3%)
 * Submitted: 2026-03-24 19:44:22 UTC
 * URL: https://leetcode.com/submissions/detail/1958181804/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root, low, high);
    }

    int preorder(TreeNode* node, int low, int high) {
        if(!node) return 0;

        int res = 0;
        if(low <= node->val && node->val <= high) res += node->val;
        if(low <= node->val) res += preorder(node->left, low, high);
        if(node->val <= high) res += preorder(node->right, low, high);

        return res;
    }
};

/**
# Approach: traverse with min/max

preorder(node, min, max, range):
    if node in range: res += node
    
    if node.val >= range[0]: preorder(node.lef, min, node, range)
    if node.val <= range[1]: preorder(node.right, node, max, range)
**/

/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 24.2 MB (beats 91.0%)
 * Submitted: 2025-12-29 14:06:28 UTC
 * URL: https://leetcode.com/submissions/detail/1868478748/
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
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        return dfs(root, count, k);
    }

    int dfs(TreeNode *node, int &count, int k) {
        if (node == nullptr) return -1;

        int res = dfs(node->left, count, k);
        if (res != -1) return res;

        count++;
        if (count == k) return node->val;

        res = dfs(node->right, count, k);
        if (res != -1) return res;

        return -1;
    }
};





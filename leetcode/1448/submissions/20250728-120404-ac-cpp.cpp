/*
 * 1448. Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 103 ms (beats 36.1%)
 * Memory: 88.4 MB (beats 63.6%)
 * Submitted: 2025-07-28 12:04:04 UTC
 * URL: https://leetcode.com/submissions/detail/1714474791/
 */


class Solution {
  public:
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }

    int dfs(TreeNode *node, int maxval) {
        if (node == nullptr) return 0;
        int count = node->val >= maxval ? 1 : 0;
        if (node->left) count += dfs(node->left, max(maxval, node->left->val));
        if (node->right) count += dfs(node->right, max(maxval, node->right->val));
        return count;
    }
};

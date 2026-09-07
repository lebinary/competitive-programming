/*
 * 1448. Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 87 ms (beats 91.0%)
 * Memory: 88.4 MB (beats 29.9%)
 * Submitted: 2025-07-28 12:03:06 UTC
 * URL: https://leetcode.com/submissions/detail/1714473920/
 */

class Solution {
  public:
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }

    int dfs(TreeNode *node, int maxval) {
        if (node == nullptr) return 0;

        int count = node->val >= maxval ? 1 : 0;
        if (node->left) {
            count += dfs(node->left, max(maxval, node->left->val));
        }
        if (node->right) {
            count += dfs(node->right, max(maxval, node->right->val));
        }

        return count;
    }
};

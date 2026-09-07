/*
 * 437. Path Sum III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 21 ms (beats 11.5%)
 * Memory: 18.9 MB (beats 89.2%)
 * Submitted: 2026-01-04 10:19:05 UTC
 * URL: https://leetcode.com/submissions/detail/1874076392/
 */

class Solution {
  public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(TreeNode *node, long long remain) {
        if (node == nullptr) return 0;

        int count = node->val == remain ? 1 : 0;
        count += dfs(node->left, remain - node->val);
        count += dfs(node->right, remain - node->val);

        return count;
    }
};


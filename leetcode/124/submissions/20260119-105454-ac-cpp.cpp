/*
 * 124. Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 27.9 MB (beats 76.2%)
 * Submitted: 2026-01-19 10:54:54 UTC
 * URL: https://leetcode.com/submissions/detail/1889766505/
 */

class Solution {
  public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return 0;

        int best = INT_MIN;
        dfs(best, root);
        return best;
    }

    int dfs(int &best, TreeNode *node) {
        if (node == nullptr) return INT_MIN;

        int leftMax = dfs(best, node->left);
        int rightMax = dfs(best, node->right);

        int nnLeftMax = max(0, leftMax);
        int nnRightMax = max(0, rightMax);

        best = max(best, node->val + nnLeftMax + nnRightMax);
        return node->val + max(nnLeftMax, nnRightMax);
    }
};

/*
 * 124. Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 28 MB (beats 21.1%)
 * Submitted: 2026-01-19 11:01:01 UTC
 * URL: https://leetcode.com/submissions/detail/1889770984/
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

        int leftGain = max(0, dfs(best, node->left));
        int rightGain = max(0, dfs(best, node->right));

        best = max(best, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
};


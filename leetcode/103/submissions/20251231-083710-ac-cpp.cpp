/*
 * 103. Binary Tree Zigzag Level Order Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.2 MB (beats 16.8%)
 * Submitted: 2025-12-31 08:37:10 UTC
 * URL: https://leetcode.com/submissions/detail/1870106360/
 */

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        bool rev = false;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            if (rev) reverse(level.begin(), level.end());
            res.push_back(level);
            rev = !rev;
        }

        return res;
    }
};

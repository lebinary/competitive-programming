/*
 * 199. Binary Tree Right Side View
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15 MB (beats 40.6%)
 * Submitted: 2025-07-10 14:14:35 UTC
 * URL: https://leetcode.com/submissions/detail/1693229074/
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();

                if (i == n - 1) res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};

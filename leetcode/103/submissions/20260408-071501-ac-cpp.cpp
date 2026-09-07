/*
 * 103. Binary Tree Zigzag Level Order Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.1 MB (beats 78.0%)
 * Submitted: 2026-04-08 07:15:01 UTC
 * URL: https://leetcode.com/submissions/detail/1972336175/
 */

// BFS with reverse
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
    
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;

        while(!q.empty()) {
            int n = q.size();

            level = vector<int>();

            for(int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(rev) reverse(level.begin(), level.end());
            res.push_back(level);
            rev = !rev;
        }

        return res;
    }
};

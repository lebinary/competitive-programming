/*
 * 1161. Maximum Level Sum of a Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 109.3 MB (beats 89.6%)
 * Submitted: 2026-03-24 19:56:52 UTC
 * URL: https://leetcode.com/submissions/detail/1958189734/
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
    int maxLevelSum(TreeNode* root) {
        int res = 1, maxSum = INT_MIN; 
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while(!q.empty()) {
            int n = q.size();

            int currSum = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(currSum > maxSum) {
                maxSum = currSum;
                res = level;
            }

            level++;
        }

        return res;
    }
};

/**
# Approach: BFS Level-traversal
- At each level: calculate the sum
- If sum > curMax: Update the res index
**/

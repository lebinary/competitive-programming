/*
 * 314. Binary Tree Vertical Order Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 42.5%)
 * Memory: 15.5 MB (beats 94.3%)
 * Submitted: 2026-03-08 19:54:40 UTC
 * URL: https://leetcode.com/submissions/detail/1942255122/
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};

        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> map;

        q.push({root, 0});
        map[0].push_back(root->val);

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; ++i) {
                const auto [node, col] = q.front();
                q.pop();

                if(node->left) {
                    q.push({node->left, col - 1});
                    map[col - 1].push_back(node->left->val);
                }

                if(node->right) {
                    q.push({node->right, col + 1});
                    map[col + 1].push_back(node->right->val);
                }
            }
        }

        vector<vector<int>> res;
        for(const auto& [col, vals] : map) {
            res.push_back(move(vals));
        }

        return res;
    }
};

/**
Approach 2: BFS level order with column

- For each level, store (node, col)
    Example: 
            (1, 0)
            /    \
        (2,-1)   (3, 1)
                  /   \ 
            (9, 0)    (11, 2)  

- Store in map[col: vector<int>]
- Since map is sorted, loop through and get the result

TC: O(n)
SC: O(n)
**/

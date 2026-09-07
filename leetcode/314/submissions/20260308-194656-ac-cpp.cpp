/*
 * 314. Binary Tree Vertical Order Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 25.5%)
 * Memory: 15.9 MB (beats 15.9%)
 * Submitted: 2026-03-08 19:46:57 UTC
 * URL: https://leetcode.com/submissions/detail/1942250730/
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
        unordered_map<int, vector<int>> map;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        q.push({root, 0});
        minHeap.push(0);
        map[0].push_back(root->val);

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; ++i) {
                auto [node, col] = q.front();
                q.pop();

                if(node->left) {
                    q.push({node->left, col - 1});
                    if(!map.count(col - 1)) minHeap.push(col - 1);
                    map[col - 1].push_back(node->left->val);
                }

                if(node->right) {
                    q.push({node->right, col + 1});
                    if(!map.count(col + 1)) minHeap.push(col + 1);
                    map[col + 1].push_back(node->right->val);
                }
            }
        }

        vector<vector<int>> res;
        while(!minHeap.empty()) {
            int col = minHeap.top();
            minHeap.pop();
            res.push_back(map[col]);
        }

        return res;
    }
};

/**
Approach: BFS level order with column

- For each level, store (node, col)
    Example: 
            (1, 0)
            /    \
        (2,-1)   (3, 1)
                  /   \ 
            (9, 0)    (11, 2)  

- Store in map[col: vector<int>]
- Store the col in minHeap
- While minHeap not empty:
    res.push(map[minHeap.pop()])

TC: O(n)
SC: O(n + col)
**/

/*
 * 863. All Nodes Distance K in Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 28.6%)
 * Memory: 15.8 MB (beats 19.5%)
 * Submitted: 2026-03-16 12:18:37 UTC
 * URL: https://leetcode.com/submissions/detail/1950026847/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<int, vector<int>> graph;
        queue<pair<TreeNode*, TreeNode*>> q;

        // BFS build a graph
        q.push({nullptr, root});

        while(!q.empty()) {
            auto [pre, curr] = q.front();
            q.pop();

            if(curr->left) {
                q.push({curr, curr->left});
                graph[curr->left->val].push_back(curr->val);
                graph[curr->val].push_back(curr->left->val);
            }
            if(curr->right) {
                q.push({curr, curr->right});
                graph[curr->right->val].push_back(curr->val);
                graph[curr->val].push_back(curr->right->val);
            }
        }

        // Get res
        vector<int> res;
        queue<pair<int, int>> q2;
        unordered_set<int> visited;

        q2.push({target->val, 0});
        visited.insert(target->val);

        while(!q2.empty()) {
            auto [node, dist] = q2.front();
            q2.pop();

            if(dist == k) {
                res.push_back(node);
                continue;
            }

            for(int nextNode : graph[node]) {
                if(visited.count(nextNode)) continue;
                
                q2.push({nextNode, dist + 1});
                visited.insert(nextNode);
            }
        }

        return res;
    }
};

/**
# Ideas:
- First, build an adj undirected graph when finding target:
    map{child -> parent, parent -> child}
- Then from target, find all children with k distance

# Approach:
- BFS to build graph
- From target, find all elements with k distance
**/

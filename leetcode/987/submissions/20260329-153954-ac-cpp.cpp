/*
 * 987. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 16.7 MB (beats 7.5%)
 * Submitted: 2026-03-29 15:39:55 UTC
 * URL: https://leetcode.com/submissions/detail/1962988599/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> sortedMap;
        preorder(root, 0, 0, sortedMap);
        
        vector<vector<int>> res(sortedMap.size());
        int i = 0;
        for(auto [col, rowMap] : sortedMap) {
            for(auto [row, vec] : rowMap) {
                sort(vec.begin(), vec.end());
                for(int num : vec) {
                    res[i].push_back(num);
                }
            }
            i++;
        }
        return res;
    }

    void preorder(TreeNode* node, int row, int col, auto& sortedMap) {
        if(!node) return;
        sortedMap[col][row].push_back(node->val);

        preorder(node->left, row + 1, col - 1, sortedMap);
        preorder(node->right, row + 1, col + 1, sortedMap);
    }
};

/**
- Preorder travese the tree, with a tag
- Sort the tag, return the result
**/

/*
 * 545. Boundary of Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 6.9%)
 * Memory: 21.8 MB (beats 12.6%)
 * Submitted: 2026-03-11 17:22:08 UTC
 * URL: https://leetcode.com/submissions/detail/1945265220/
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right) return { root->val };

        vector<int> leftBound, rightBound, leaves;
        
        getLeft(leftBound, root->left);
        getRight(rightBound, root->right);
        getLeaves(leaves, root);

        reverse(rightBound.begin(), rightBound.end());

        vector<int> res = {root->val};
        res.insert(res.end(), leftBound.begin(), leftBound.end());
        res.insert(res.end(), leaves.begin(), leaves.end());
        res.insert(res.end(), rightBound.begin(), rightBound.end());
        return res;
    }

    void getLeft(vector<int> &res, TreeNode* node) {
        if(!node || (!node->left && !node->right)) return;
        
        res.push_back(node->val);

        if(node->left) {
            getLeft(res, node->left);
        } else {
            getLeft(res, node->right);
        }
    }
    
    void getRight(vector<int> &res, TreeNode* node) {
        if(!node || (!node->left && !node->right)) return;

        res.push_back(node->val);

        if(node->right) {
            getRight(res, node->right);
        } else {
            getRight(res, node->left);
        }
    }

    void getLeaves(vector<int> &res, TreeNode*node) {
        if(!node) return;
        if(!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }

        getLeaves(res, node->left);
        getLeaves(res, node->right);
    }
};


/**
- Must have root->left
- Any node:
    - node's left is in boundary
    - if no node->left, then right is in boundary
    - leftmost leaf is not in the boundary

Ideas: go through the tree 3 times
- get left boundary -> [node->left, ... leaf's parent]
- get right boundary -> [leaft's parent, ..., node->right]
- get all the leafs

TC: O(number of nodes)
SC: O(number of nodes)
**/

/*
 * 129. Sum Root to Leaf Numbers
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 12 MB (beats 19.1%)
 * Submitted: 2026-03-10 13:08:26 UTC
 * URL: https://leetcode.com/submissions/detail/1943934186/
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        int res = 0;
        preorder(res, 0, root);
        return res;
    }

    void preorder(int &res, int num, TreeNode* node) {
        if(!node) return;
        
        num = num * 10 + node->val;
        preorder(res, num, node->left);
        preorder(res, num, node->right);
        
        if(!node->left && !node->right) res += num;
    }
};

/**
Approach 1: preorder traverse
res = 0 
preorder(num, node)
    if !node: return
    
    num = num * 10 + node->val
    preorder(num, node->left)
    preorder(num, node->right)
    if(!node->left && !node->right) res += sum
return res

**/

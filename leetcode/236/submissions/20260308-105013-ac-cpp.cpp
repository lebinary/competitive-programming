/*
 * 236. Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 418 ms (beats 5.1%)
 * Memory: 17.4 MB (beats 100.0%)
 * Submitted: 2026-03-08 10:50:13 UTC
 * URL: https://leetcode.com/submissions/detail/1941863111/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root == q) return root;

        int found = preorder(root->left, p, q);
        if(found == 2) return lowestCommonAncestor(root->left, p, q);
        else if(found == 1) return root;
        else return lowestCommonAncestor(root->right, p, q);
    }

    int preorder(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return 0;

        int res = 0;
        if(node == p) res++;
        if(node == q) res++;
        if(res == 2) return res;
        
        return res + preorder(node->left, p, q) + preorder(node->right, p, q);
    }
};

/**
Approach 1: preorder
- IF node == p || node == q: return node
- ELSE:
    traverse leftsubtree:
        if count == 2: traverse left
        if count == 1: return
        else: traverse right

**/

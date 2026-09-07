/*
 * 270. Closest Binary Search Tree Value
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 21.3 MB (beats 47.4%)
 * Submitted: 2026-03-22 14:56:55 UTC
 * URL: https://leetcode.com/submissions/detail/1955848358/
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
    int closestValue(TreeNode* root, double target) {
        return preorder(root, INT_MIN, INT_MAX, target);
    }

    int preorder(TreeNode* node, int lo, int hi, double target) {
        if(!node) return abs(target - lo) <= abs(target - hi) ? lo : hi;
        if(target < node->val) return preorder(node->left, lo, node->val, target);
        else return preorder(node->right, node->val, hi, target);
    }
};

/**
Approach 1: inorder + binary search
- inorder traverse to create a sorted array
- binary search rightmost value s.t < target
- binary search leftmost value s.t > target
- return one with smallest dist
TC: O(nodes)
SC: O(nodes)

Approach 2: preorder traverse, for each node
- if target in range [min, node]
    dfs(node.left, min, node)
- if target in range [node, max]
    dfs(node.right, node, max)
- base case: no node
    ret | min - target | < | max - target | ? min : max;
TC: O(logn)
SC: (alpha)
**/

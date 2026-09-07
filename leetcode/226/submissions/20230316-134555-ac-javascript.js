/*
 * 226. Invert Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 57 ms (beats 0.9%)
 * Memory: 41.7 MB (beats 100.0%)
 * Submitted: 2023-03-16 13:45:55 UTC
 * URL: https://leetcode.com/submissions/detail/916289202/
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if(!root){
        return null;
    }
    tmp = root.left;
    root.left = root.right;
    root.right = tmp;

    invertTree(root.left);
    invertTree(root.right);

    return root;
};

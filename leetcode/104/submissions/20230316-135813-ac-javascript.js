/*
 * 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 68 ms (beats 4.2%)
 * Memory: 45.3 MB (beats 100.0%)
 * Submitted: 2023-03-16 13:58:13 UTC
 * URL: https://leetcode.com/submissions/detail/916295275/
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
 * @return {number}
 */
var maxDepth = function(root) {
    if(!root){
        return 0;
    }
    
    const maxLeftDepth = 1 + maxDepth(root.left);
    const maxRightDepth = 1 + maxDepth(root.right);

    return Math.max(maxLeftDepth, maxRightDepth);
};

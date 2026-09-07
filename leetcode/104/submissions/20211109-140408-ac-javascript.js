/*
 * 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 80 ms (beats 4.2%)
 * Memory: 41.5 MB (beats 100.0%)
 * Submitted: 2021-11-09 14:04:08 UTC
 * URL: https://leetcode.com/submissions/detail/584496458/
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
    if(root === null){
        return 0;
    }
    let leftCount = 1 + maxDepth(root.left);
    let rightCount = 1 + maxDepth(root.right);
    return Math.max(leftCount, rightCount);
};

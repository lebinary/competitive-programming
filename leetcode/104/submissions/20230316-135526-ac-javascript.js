/*
 * 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 66 ms (beats 4.2%)
 * Memory: 45 MB (beats 100.0%)
 * Submitted: 2023-03-16 13:55:26 UTC
 * URL: https://leetcode.com/submissions/detail/916293917/
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
    const recursive = (root, depth) => {
        if(!root){
            return depth;
        }
        
        const maxLeftDepth = recursive(root.left, depth + 1);
        const maxRightDepth = recursive(root.right, depth + 1);

        return Math.max(maxLeftDepth, maxRightDepth);
    }

    return recursive(root, 0);
};

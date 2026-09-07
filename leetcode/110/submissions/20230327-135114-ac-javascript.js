/*
 * 110. Balanced Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 84 ms (beats 5.5%)
 * Memory: 48.4 MB (beats 100.0%)
 * Submitted: 2023-03-27 13:51:14 UTC
 * URL: https://leetcode.com/submissions/detail/923032256/
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
 * @return {boolean}
 */
var isBalanced = function(root) {
    const dfs = (root) => {
        if(!root){
            return [true, 0];
        }

        const left = dfs(root.left);
        const right = dfs(root.right);

        const balanced = left[0] && right[0] && Math.abs(left[1] - right[1]) <= 1;

        return [balanced, 1 + Math.max(left[1], right[1])];
    }

    return dfs(root)[0];
};

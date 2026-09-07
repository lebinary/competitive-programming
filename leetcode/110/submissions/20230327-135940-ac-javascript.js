/*
 * 110. Balanced Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 76 ms (beats 5.5%)
 * Memory: 48 MB (beats 100.0%)
 * Submitted: 2023-03-27 13:59:40 UTC
 * URL: https://leetcode.com/submissions/detail/923036645/
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
    let balanced = true;
    const dfs = (root) => {
        if(!root){
            return 0;
        }

        const left = dfs(root.left);
        const right = dfs(root.right);

        balanced = balanced && Math.abs(left - right) <= 1;

        return 1 + Math.max(left, right);

    }
    dfs(root);

    return balanced;
};

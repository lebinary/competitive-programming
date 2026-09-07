/*
 * 543. Diameter of Binary Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 72 ms (beats 6.6%)
 * Memory: 45.4 MB (beats 100.0%)
 * Submitted: 2023-03-16 14:51:30 UTC
 * URL: https://leetcode.com/submissions/detail/916322787/
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
var diameterOfBinaryTree = function(root) {
    let maxDiameter = 0;

    const dfs = (root) => {
        if(root === null){
            return -1;
        }

        const leftMaxHeight = dfs(root.left);
        const rightMaxHeight = dfs(root.right);
        
        maxDiameter = Math.max(maxDiameter, 2 + leftMaxHeight + rightMaxHeight)

        return 1 + Math.max(leftMaxHeight, rightMaxHeight);
    }
    
    dfs(root);
    return maxDiameter;
};

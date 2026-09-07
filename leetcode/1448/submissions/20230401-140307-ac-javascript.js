/*
 * 1448. Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 169 ms (beats 5.3%)
 * Memory: 65.9 MB (beats 100.0%)
 * Submitted: 2023-04-01 14:03:07 UTC
 * URL: https://leetcode.com/submissions/detail/925926776/
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
var goodNodes = function(root) {
    if(!root) return 0;

    const dfs = (node, cur_max) => {
        if(!node) {
            return 0;
        }

        let res = 0;
        if(node.left && node.left.val >= cur_max){
            res += 1;
        }

        if(node.right && node.right.val >= cur_max){
            res += 1;
        }

        // Recusive left side
        const l = dfs(node.left, Math.max(cur_max, node.left? node.left.val : cur_max));

        // Recusive right side
        const r = dfs(node.right, Math.max(cur_max, node.right? node.right.val : cur_max));

        return res + l + r; 
    }

    return 1 + dfs(root, root.val);
};

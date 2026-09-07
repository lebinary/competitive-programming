/*
 * 1448. Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 167 ms (beats 5.3%)
 * Memory: 66.2 MB (beats 100.0%)
 * Submitted: 2023-04-01 14:11:13 UTC
 * URL: https://leetcode.com/submissions/detail/925930513/
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
        if(node.val >= cur_max){
            res += 1;
        }

        const new_max = Math.max(cur_max, node.val);

        // Recusive left side
        res += dfs(node.left, new_max);

        // Recusive right side
        res += dfs(node.right, new_max);

        return res; 
    }

    return dfs(root, root.val);
};

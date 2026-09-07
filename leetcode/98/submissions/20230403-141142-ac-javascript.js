/*
 * 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 71 ms (beats 5.1%)
 * Memory: 45.6 MB (beats 100.0%)
 * Submitted: 2023-04-03 14:11:42 UTC
 * URL: https://leetcode.com/submissions/detail/927242660/
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
var isValidBST = function(root) {

    const dfs = (node, min, max) => {
        if(!node){
            return true;
        }

        if(!(node.val < max && node.val > min)){
            return false;
        }

        const l = dfs(node.left, min, node.val);
        const r = dfs(node.right, node.val, max);

        return l && r;
    }

    return dfs(root, Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY);
};

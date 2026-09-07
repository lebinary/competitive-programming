/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 90 ms (beats 6.4%)
 * Memory: 51.7 MB (beats 100.0%)
 * Submitted: 2023-03-30 13:57:03 UTC
 * URL: https://leetcode.com/submissions/detail/924836615/
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    let cur = root;
    // Traverse down from the top, find the lowest split point
    while(cur){
        if(p.val < cur.val && q.val < cur.val){
            cur = cur.left;
        }
        else if(p.val > cur.val && q.val > cur.val){
            cur = cur.right;
        }
        // Found the split point
        else{
            return cur;
        }
    }
};

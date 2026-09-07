/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 70 ms (beats 5.3%)
 * Memory: 48.1 MB (beats 100.0%)
 * Submitted: 2023-04-10 14:16:50 UTC
 * URL: https://leetcode.com/submissions/detail/931312786/
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
 * @param {number} k
 * @return {number}
 */

// Inorder traversal
var kthSmallest = function(root, k) {
    let n = 0;
    let stack = [];
    let cur = root;

    while(stack.length >= 0){
        // go to most left node
        while(cur){
            stack.push(cur);
            cur = cur.left;
        }
        // pop out previous node
        cur = stack.pop();
        n+=1;
        if(n === k) {
            return cur.val;
        } 

        // check right side
        cur = cur.right;
    }
};

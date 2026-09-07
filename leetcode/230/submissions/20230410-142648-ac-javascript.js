/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 76 ms (beats 5.3%)
 * Memory: 48.9 MB (beats 100.0%)
 * Submitted: 2023-04-10 14:26:48 UTC
 * URL: https://leetcode.com/submissions/detail/931318266/
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
    const resArray = [];

    const inorder = (root) => {
        if(!root){
            return;
        }

        inorder(root.left);
        
        resArray.push(root.val);

        inorder(root.right);
    }
    inorder(root);
    
    return resArray[k-1];
};

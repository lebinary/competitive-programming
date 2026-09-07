/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 89 ms (beats 6.4%)
 * Memory: 51.7 MB (beats 100.0%)
 * Submitted: 2023-03-30 14:39:32 UTC
 * URL: https://leetcode.com/submissions/detail/924857893/
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
    // Base case
    if(!root){
        return null;
    }

    // if left node or right node is the same as root -> return root
    if(root.val === p.val || root.val === q.val){
        return root;
    }

    // Look for LCA in left sub-tree and right sub-tree
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);

    // If return value of both sub-trees are not null, then root is the LCA
    if(left && right){
        return root;
    }

    // Otherwise check if left subtree or right subtree is LCA
    return left? left : right;
};

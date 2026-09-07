/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 80 ms (beats 6.4%)
 * Memory: 52.5 MB (beats 100.0%)
 * Submitted: 2023-03-30 15:59:44 UTC
 * URL: https://leetcode.com/submissions/detail/924899904/
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

    // Check if both keys (p , q) in left sub-tree and right sub-tree
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);

    // If return value of both sub-trees are not null (meaning p and q are in both subtrees), then root is the LCA
    if(left && right){
        return root;
    }

    // Otherwise check if left subtree or right subtree (p and q both in 1 side of the tree)
    return left? left : right;
};

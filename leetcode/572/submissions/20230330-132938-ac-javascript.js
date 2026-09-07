/*
 * 572. Subtree of Another Tree
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 87 ms (beats 5.4%)
 * Memory: 48.8 MB (beats 100.0%)
 * Submitted: 2023-03-30 13:29:38 UTC
 * URL: https://leetcode.com/submissions/detail/924823603/
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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) {
    if(!root){
        return false;
    }

    if(!subRoot) {
        return true;
    }

    if(isSameTree(root, subRoot)){
        return true;
    }

    const l = isSubtree(root.left, subRoot);
    const r = isSubtree(root.right, subRoot);

    return l || r;
};

var isSameTree = function(p, q) {
    if(!p && !q){
        return true;
    }

    if(p && q && p.val === q.val){
        const l = isSameTree(p.left, q.left);
        const r = isSameTree(p.right, q.right);

        return l && r;
    }

    return false;
};

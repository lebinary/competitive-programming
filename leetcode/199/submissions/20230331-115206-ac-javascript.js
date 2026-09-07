/*
 * 199. Binary Tree Right Side View
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 59 ms (beats 3.1%)
 * Memory: 43.5 MB (beats 100.0%)
 * Submitted: 2023-03-31 11:52:06 UTC
 * URL: https://leetcode.com/submissions/detail/925345604/
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
 * @return {number[]}
 */

// BREATH FIRST SEARCH (PUSH ONLY 1 NODE FROM RIGHT TO LEFT TO RESULT LIST)
var rightSideView = function(root) {
    const res = [];
    const q = [];

    q.push(root);

    while(q.length > 0){
        const n = q.length;
        const level = [];

        for(let i = 0; i < n; i++){
            const node = q.shift();
            if(node){
                level.push(node.val);
                q.push(node.left);
                q.push(node.right);
            }
        }

        if(level.length > 0){
            res.push(level.pop());
        }
    }

    return res;
};

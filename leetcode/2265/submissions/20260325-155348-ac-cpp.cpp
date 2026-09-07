/*
 * 2265. Count Nodes Equal to Average of Subtree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 10 ms (beats 38.4%)
 * Memory: 15.8 MB (beats 65.2%)
 * Submitted: 2026-03-25 15:53:48 UTC
 * URL: https://leetcode.com/submissions/detail/1959022704/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res;
public:
    int averageOfSubtree(TreeNode* root) {
        this->res = 0;
        postorder(root);
        return res;
    }

    pair<int, int> postorder(TreeNode* node) {
        if(!node) return {0, 0};

        auto [leftTotal, leftCount] = postorder(node->left);
        auto [rightTotal, rightCount] = postorder(node->right);

        int total = node->val + leftTotal + rightTotal;
        int count = 1 + leftCount + rightCount;
        
        if(total / count == node->val) res++;
        return {total, count}; 
    }
};

/**
# Approach: postorder traversal:

postorder(node)
    left avg = postorder
    right avg = postorder

    count = 1
    if left: count++
    if right: count++

    return (left avg + right avg + node) / count
**/

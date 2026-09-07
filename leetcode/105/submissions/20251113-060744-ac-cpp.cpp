/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 23 ms (beats 7.6%)
 * Memory: 74.5 MB (beats 6.3%)
 * Submitted: 2025-11-13 06:07:44 UTC
 * URL: https://leetcode.com/submissions/detail/1828469330/
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
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), root->val);
        int rootIdx = it - inorder.begin();

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightInorder(inorder.begin() + rootIdx + 1, inorder.end());
        vector<int> rightPreorder(preorder.begin() + 1 + leftPreorder.size(), preorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};




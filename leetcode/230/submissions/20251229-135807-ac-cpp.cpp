/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 24.3 MB (beats 91.0%)
 * Submitted: 2025-12-29 13:58:08 UTC
 * URL: https://leetcode.com/submissions/detail/1868471971/
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
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        vector<TreeNode *> stack;
        stack.push_back(root);
        TreeNode *node = root;

        while (!stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->left;
            }

            node = stack.back();
            stack.pop_back();

            count++;
            if (count == k) return node->val;

            node = node->right;
        }

        return -1;
    }
};


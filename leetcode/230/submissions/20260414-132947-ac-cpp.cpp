/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 24.4 MB (beats 67.6%)
 * Submitted: 2026-04-14 13:29:48 UTC
 * URL: https://leetcode.com/submissions/detail/1978297335/
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
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();

        if (top->right) {
            TreeNode* node = top->right;
            while (node) {
                st.push(node);
                node = node->left;
            }
        }

        return top->val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;

        int res = -1;
        BSTIterator iterator(root);
        for (int i = 0; i < k; i++)
            res = iterator.next();

        return res;
    }
};





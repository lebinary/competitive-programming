/*
 * 173. Binary Search Tree Iterator
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 75.5%)
 * Memory: 32 MB (beats 67.8%)
 * Submitted: 2026-04-08 07:36:08 UTC
 * URL: https://leetcode.com/submissions/detail/1972350639/
 */

class BSTIterator {
    stack<TreeNode*> st;

  public:

    BSTIterator(TreeNode *root) {
        TreeNode* curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(node->right) {
            TreeNode* curr = node->right;
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

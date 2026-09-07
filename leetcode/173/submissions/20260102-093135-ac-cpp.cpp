/*
 * 173. Binary Search Tree Iterator
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 37.7%)
 * Memory: 32 MB (beats 67.8%)
 * Submitted: 2026-01-02 09:31:35 UTC
 * URL: https://leetcode.com/submissions/detail/1871866799/
 */

class BSTIterator {
  public:
    TreeNode *node;
    stack<TreeNode *> stack;

    BSTIterator(TreeNode *root) { this->node = root; }

    int next() {
        while (node != nullptr) {
            stack.push(node);
            node = node->left;
        }

        node = stack.top();
        stack.pop();

        int res = node->val;
        node = node->right;
        return res;
    }

    bool hasNext() { return !stack.empty() || node != nullptr; }
};

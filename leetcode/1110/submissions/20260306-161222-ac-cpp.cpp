/*
 * 1110. Delete Nodes And Return Forest
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 70.4%)
 * Memory: 26.7 MB (beats 67.2%)
 * Submitted: 2026-03-06 16:12:23 UTC
 * URL: https://leetcode.com/submissions/detail/1940004274/
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;

        root = postorder(root, delSet, res);

        if(root) res.push_back(root);
        return res;
    }

    TreeNode* postorder(TreeNode* node, unordered_set<int>&delSet, vector<TreeNode*>& res) {
        if(!node) return nullptr;

        node->left = postorder(node->left, delSet, res);
        node->right = postorder(node->right, delSet, res);

        if(delSet.count(node->val)) {
            if(node->left) res.push_back(node->left);
            if(node->right) res.push_back(node->right);
            return nullptr;
        }

        return node;
    }
};

/**
Key insight: Any node deleted, its children become orphans => add those children to result

Approach: postorder traversal
- postorder(node, res):
    if not node: return

    postorder(node.left)
    postorder(node.right)

    if to_delete.has(node):
        res.push(node.left)
        res.push(node.right)
**/

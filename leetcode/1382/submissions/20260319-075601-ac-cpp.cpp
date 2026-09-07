/*
 * 1382. Balance a Binary Search Tree
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1386 ms (beats 5.0%)
 * Memory: 720.2 MB (beats 5.3%)
 * Submitted: 2026-03-19 07:56:01 UTC
 * URL: https://leetcode.com/submissions/detail/1952822402/
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sortedNodes;
        inorder(root, sortedNodes);
        return build(sortedNodes, 0, sortedNodes.size() - 1);
    }

    void inorder(TreeNode* node, vector<TreeNode*>& sortedNodes) {
        if(!node) return;
        inorder(node->left, sortedNodes);
        sortedNodes.push_back(node);
        inorder(node->right, sortedNodes);
    }

    TreeNode* build(vector<TreeNode*> sortedNodes, int l, int r) {
        if(l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = sortedNodes[m];
        root->left = build(sortedNodes, l, m - 1);
        root->right = build(sortedNodes, m + 1, r);
        return root;
    }
};

/**
1
 \
  2
   \
    3
     \
      4

dfs(node=2): 
 - nodeRight, depthRight = dfs(rightSubtree)
 - nodeLeft, depthLeft = dfs(leftSubtree)
 - because depthRight - depthLeft > 1:
    - nodeRight.left = node
    return nodeRight, depth - 1

 1
  \
   3
  / \
 2   4

There are 3 cases:
- |leftLevels - rightLevels| <= 1: do nothing
- rightLevels > leftLevels by more than 1:
    - nodeRight.left = node
    - node.right = None
    return nodeRight

- leftLevels > rightLevels by more than 1:
    - nodeLeft.right = node
    - node.left = None
    return nodeLeft

=> VERY COMPLICATED, dont try to balance in-place

# Approach 2:
- Traverse inorder to get sorted array of node
- Reconstruct the tree that is balanced
**/

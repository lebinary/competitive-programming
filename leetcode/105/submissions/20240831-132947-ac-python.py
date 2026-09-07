# 105. Construct Binary Tree from Preorder and Inorder Traversal
# Difficulty: Medium
# Status: Accepted
# Runtime: 132 ms (beats 42.1%)
# Memory: 86.4 MB (beats 40.1%)
# Submitted: 2024-08-31 13:29:47 UTC
# URL: https://leetcode.com/submissions/detail/1374182900/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return
        
        root = TreeNode()
        root.val = preorder[0]
        root_idx = inorder.index(root.val)

        # Recursive build left tree
        left_inorder = inorder[ : root_idx]
        left_preorder = preorder[1: len(left_inorder)+1]
        root.left = self.buildTree(left_preorder, left_inorder)
        
        # Recursive build right tree
        right_inorder = inorder[root_idx + 1 :]
        right_preorder = preorder[len(left_preorder) + 1 :]
        root.right = self.buildTree(right_preorder, right_inorder)

        return root

# 236. Lowest Common Ancestor of a Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 4915 ms (beats 5.1%)
# Memory: 21.1 MB (beats 100.0%)
# Submitted: 2024-09-26 13:41:08 UTC
# URL: https://leetcode.com/submissions/detail/1402942636/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None

        if root.val == p.val or root.val == q.val:
            return root
        
        if (self.findNode(root.left, p) and self.findNode(root.right, q) or
            self.findNode(root.left, q) and self.findNode(root.right, p) ):
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        return left or right

    def findNode(self, root, node):
        if not root:
            return False
        
        if root.val == node.val:
            return True
        
        return self.findNode(root.left, node) or self.findNode(root.right, node)

# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 63 ms (beats 68.0%)
# Memory: 20.2 MB (beats 100.0%)
# Submitted: 2024-09-13 04:44:49 UTC
# URL: https://leetcode.com/submissions/detail/1388385967/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        curr = root

        while curr:
            # p and q on the left subtree
            if p.val < curr.val and q.val < curr.val:
                curr = curr.left
            # p and q on the right subtree
            elif p.val > curr.val and q.val > curr.val:
                curr = curr.right
            # either p or q equals curr node
            else:
                return curr

# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 62 ms (beats 72.6%)
# Memory: 20.2 MB (beats 100.0%)
# Submitted: 2024-09-01 12:08:16 UTC
# URL: https://leetcode.com/submissions/detail/1375343751/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # ensure p always smaller the q
        if p.val > q.val:
            p, q = q, p
        
        curr = root
        while curr:
            if p.val <= curr.val <= q.val: # there is a split, or p is direct ancestor of q (and vice versa)
                return curr
            elif curr.val > q.val: # p and q in left sub-tree
                curr = curr.left
            else: # p and q in right sub-tree
                curr = curr.right
        
        return None # p and q are not in the tree

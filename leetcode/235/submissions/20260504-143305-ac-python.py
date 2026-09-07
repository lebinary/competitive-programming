# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 44 ms (beats 92.6%)
# Memory: 20.6 MB (beats 10.6%)
# Submitted: 2026-05-04 14:33:05 UTC
# URL: https://leetcode.com/submissions/detail/1995020894/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        node = root
        while node:
            if p.val < node.val and q.val < node.val:
                node = node.left
            elif p.val > node.val and q.val > node.val:
                node = node.right
            else:
                return node
        return None                

        

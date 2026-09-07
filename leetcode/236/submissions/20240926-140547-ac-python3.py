# 236. Lowest Common Ancestor of a Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 55 ms (beats 100.0%)
# Memory: 21.1 MB (beats 100.0%)
# Submitted: 2024-09-26 14:05:47 UTC
# URL: https://leetcode.com/submissions/detail/1402965236/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = [0]

        def dfs(node):
            if not node:
                return False

            left = dfs(node.left)
            right = dfs(node.right)

            mid = node == p or node == q

            if mid + left + right >= 2:
                res[0] = node
            
            return mid or left or right
             
        dfs(root)
        return res[0]
            
            


# 543. Diameter of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 1 ms (beats 84.7%)
# Memory: 22.2 MB (beats 36.2%)
# Submitted: 2026-04-24 17:46:11 UTC
# URL: https://leetcode.com/submissions/detail/1987197792/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = [0]

        def dfs(node):
            if not node:
                return 0
            
            leftDepth = dfs(node.left)
            rightDepth = dfs(node.right)

            diameter[0] = max(diameter[0], leftDepth + rightDepth)

            return 1 + max(leftDepth, rightDepth)

        dfs(root)

        return diameter[0]

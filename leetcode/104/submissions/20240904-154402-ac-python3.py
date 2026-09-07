# 104. Maximum Depth of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 28 ms (beats 9.0%)
# Memory: 17.5 MB (beats 100.0%)
# Submitted: 2024-09-04 15:44:02 UTC
# URL: https://leetcode.com/submissions/detail/1378952236/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import math

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0

        # DFS iterative solution
        stack = [(root, 1)]
        max_depth = 1

        while stack:
            node, depth = stack.pop()
            max_depth = max(max_depth, depth)

            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:                
                stack.append((node.right, depth + 1))
        return max_depth

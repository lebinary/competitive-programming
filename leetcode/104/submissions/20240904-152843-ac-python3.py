# 104. Maximum Depth of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 41 ms (beats 9.0%)
# Memory: 17.6 MB (beats 100.0%)
# Submitted: 2024-09-04 15:28:43 UTC
# URL: https://leetcode.com/submissions/detail/1378937039/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0

        # DFS recursive solution
        left_max_depth = self.maxDepth(root.left)
        right_max_depth = self.maxDepth(root.right)

        return 1 + max(left_max_depth, right_max_depth)

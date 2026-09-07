# 124. Binary Tree Maximum Path Sum
# Difficulty: Hard
# Status: Accepted
# Runtime: 70 ms (beats 5.8%)
# Memory: 22.6 MB (beats 100.0%)
# Submitted: 2024-09-05 13:59:53 UTC
# URL: https://leetcode.com/submissions/detail/1379990953/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root: return 0

        # DFS iterative approach
        stack = [(root, False)]
        max_sum = root.val
        maxes = {}

        while stack:
            node, visited = stack.pop()

            if visited:
                left_max = max(maxes.get(node.left, 0), 0)
                right_max = max(maxes.get(node.right, 0), 0)

                max_sum = max(max_sum, node.val + left_max + right_max)
                
                maxes[node] = node.val + max(left_max, right_max)
            else:
                stack.append((node, True))

                if node.left:
                  stack.append((node.left, False))
                if node.right:
                  stack.append((node.right, False))

        return max_sum

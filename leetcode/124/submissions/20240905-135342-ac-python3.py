# 124. Binary Tree Maximum Path Sum
# Difficulty: Hard
# Status: Accepted
# Runtime: 75 ms (beats 5.8%)
# Memory: 22.7 MB (beats 100.0%)
# Submitted: 2024-09-05 13:53:42 UTC
# URL: https://leetcode.com/submissions/detail/1379984782/

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
                left_max = maxes.get(node.left, float('-inf'))
                right_max = maxes.get(node.right, float('-inf'))

                max_sum = max(max_sum,
                  node.val,
                  left_max,
                  right_max,
                  node.val + left_max,
                  node.val + right_max,
                  node.val + left_max + right_max
                )
                
                maxes[node] = max(node.val, node.val + left_max, node.val + right_max)
            else:
                stack.append((node, True))

                if node.left:
                  stack.append((node.left, False))
                if node.right:
                  stack.append((node.right, False))

        return max_sum

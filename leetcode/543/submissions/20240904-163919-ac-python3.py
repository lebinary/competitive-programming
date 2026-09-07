# 543. Diameter of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 58 ms (beats 5.0%)
# Memory: 18.8 MB (beats 100.0%)
# Submitted: 2024-09-04 16:39:19 UTC
# URL: https://leetcode.com/submissions/detail/1379010963/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # DFS iterative approach
        # Diameter = left height + right height
        if not root: return 0

        stack = [(root, False)]
        heights = {}
        diameter = 0

        while stack:
            node, visited = stack.pop()

            if visited:
                left_height = heights.get(node.left, 0)
                right_height = heights.get(node.right, 0)

                diameter = max(diameter, left_height + right_height)
                
                heights[node] = 1 + max(left_height, right_height)
            else:
                stack.append((node, True))

                if node.left:
                    stack.append((node.left, False))
                if node.right:
                    stack.append((node.right, False))
        
        return diameter

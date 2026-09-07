# 543. Diameter of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 37 ms (beats 5.0%)
# Memory: 19.3 MB (beats 100.0%)
# Submitted: 2024-09-04 16:28:46 UTC
# URL: https://leetcode.com/submissions/detail/1378999104/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        # diameter of any node = left height + right height
        def calc_height(node):
            if not node: return 0

            left_height = calc_height(node.left)
            right_height = calc_height(node.right)

            self.diameter = max(self.diameter, left_height + right_height)

            return 1 + max(left_height, right_height)
        
        calc_height(root)

        return self.diameter

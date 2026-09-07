# 110. Balanced Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 40 ms (beats 5.3%)
# Memory: 17.7 MB (beats 100.0%)
# Submitted: 2024-09-05 04:22:57 UTC
# URL: https://leetcode.com/submissions/detail/1379511720/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.res = True

        def calc_height(node):
            if not node: 
                return 1
            
            left_height = calc_height(node.left)
            right_height = calc_height(node.right)

            if abs(left_height - right_height) > 1:
                self.res = False
            
            return 1 + max(left_height, right_height)
        
        calc_height(root)

        return self.res

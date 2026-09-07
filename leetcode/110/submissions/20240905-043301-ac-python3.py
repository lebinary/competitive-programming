# 110. Balanced Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 42 ms (beats 5.3%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2024-09-05 04:33:01 UTC
# URL: https://leetcode.com/submissions/detail/1379519499/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def calc_height_balance(node: TreeNode):
            if not node:
                return (0, True)

            left_height, left_is_balanced = calc_height_balance(node.left)    
            right_height, right_is_balanced = calc_height_balance(node.right)    

            node_height = 1 + max(left_height, right_height)
            node_is_balanced = left_is_balanced and right_is_balanced and abs(left_height - right_height) <= 1

            return (node_height, node_is_balanced)

        _, root_is_balanced = calc_height_balance(root) 
        return root_is_balanced

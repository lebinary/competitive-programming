# 124. Binary Tree Maximum Path Sum
# Difficulty: Hard
# Status: Accepted
# Runtime: 63 ms (beats 5.8%)
# Memory: 21 MB (beats 100.0%)
# Submitted: 2024-09-05 14:03:26 UTC
# URL: https://leetcode.com/submissions/detail/1379994421/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = [root.val]

        def dfs(node):
            if not node: return 0

            left_max = dfs(node.left)
            right_max = dfs(node.right)

            #non-negative
            nn_left_max = max(left_max, 0)
            nn_right_max = max(right_max, 0)

            res[0] = max(res[0], node.val + nn_left_max + nn_right_max)

            return node.val + max(nn_left_max, nn_right_max)
        
        dfs(root)
        return res[0]

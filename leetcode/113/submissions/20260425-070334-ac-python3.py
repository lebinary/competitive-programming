# 113. Path Sum II
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 20.2 MB (beats 63.8%)
# Submitted: 2026-04-25 07:03:34 UTC
# URL: https://leetcode.com/submissions/detail/1987520594/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        path = []

        def preorder(node, total):
            if not node:
                return
            
            path.append(node.val)
            total += node.val

            if not node.left and not node.right:
                if total == targetSum:
                    res.append(list(path))
            else:
                preorder(node.left, total)
                preorder(node.right, total)

            path.pop()
        
        preorder(root, 0)
        return res

# 100. Same Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 34 ms (beats 0.3%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-05 04:49:51 UTC
# URL: https://leetcode.com/submissions/detail/1379533289/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if (not p and q) or (p and not q):
            return False
        
        curr_same = p.val == q.val
        left_same = self.isSameTree(p.left, q.left)
        right_same = self.isSameTree(p.right, q.right)

        return curr_same and left_same and right_same

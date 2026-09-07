# 100. Same Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 32 ms (beats 0.3%)
# Memory: 16.4 MB (beats 100.0%)
# Submitted: 2024-09-05 05:20:13 UTC
# URL: https://leetcode.com/submissions/detail/1379560032/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [(p, q)]

        while stack:
            curr_p, curr_q = stack.pop()

            if not curr_p and not curr_q:
                continue
            if (not curr_p and curr_q) or (curr_p and not curr_q):
                return False
            if (curr_p.val != curr_q.val):
                return False
            
            stack.append((curr_p.right, curr_q.right))
            stack.append((curr_p.left, curr_q.left))
        
        return True

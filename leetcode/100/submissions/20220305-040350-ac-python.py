# 100. Same Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 23 ms (beats 0.6%)
# Memory: 13.4 MB (beats 1.2%)
# Submitted: 2022-03-05 04:03:50 UTC
# URL: https://leetcode.com/submissions/detail/653560014/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    # Recursive DFS
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q: return True
        if not p or not q: return False
        if p.val != q.val: return False
        
        left_res = self.isSameTree(p.left, q.left)
        right_res = self.isSameTree(p.right, q.right)
        
        return left_res and right_res
        

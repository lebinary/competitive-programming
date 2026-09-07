# 1650. Lowest Common Ancestor of a Binary Tree III
# Difficulty: Medium
# Status: Accepted
# Runtime: 68 ms (beats 12.8%)
# Memory: 22.4 MB (beats 70.0%)
# Submitted: 2026-04-25 07:40:46 UTC
# URL: https://leetcode.com/submissions/detail/1987542746/

"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        pDist = 0
        currP = p
        while currP:
            pDist += 1
            currP = currP.parent
        
        qDist = 0
        currQ = q
        while currQ:
            qDist += 1
            currQ = currQ.parent
        
        while pDist > qDist:
            p = p.parent
            pDist -= 1
        
        while qDist > pDist:
            q = q.parent
            qDist -= 1
            
        while p != q:
            p = p.parent
            q = q.parent
        
        return p

# 1650. Lowest Common Ancestor of a Binary Tree III
# Difficulty: Medium
# Status: Accepted
# Runtime: 70 ms (beats 8.0%)
# Memory: 22.4 MB (beats 70.0%)
# Submitted: 2026-04-25 07:38:25 UTC
# URL: https://leetcode.com/submissions/detail/1987541399/

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
        
        if pDist >= qDist:
            for _ in range(pDist - qDist):
                p = p.parent
        else:
            for _ in range(qDist - pDist):
                q = q.parent
            
        while p != q:
            p = p.parent
            q = q.parent
        
        return p

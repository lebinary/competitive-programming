# 116. Populating Next Right Pointers in Each Node
# Difficulty: Medium
# Status: Accepted
# Runtime: 61 ms (beats 32.5%)
# Memory: 20.6 MB (beats 49.7%)
# Submitted: 2026-04-25 07:16:28 UTC
# URL: https://leetcode.com/submissions/detail/1987528234/

"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None

        q = deque([root])
        while q:
            currSize = len(q)
            for i in range(currSize):
                node = q.popleft()

                node.next = q[0] if i < currSize - 1 else None

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        
        return root

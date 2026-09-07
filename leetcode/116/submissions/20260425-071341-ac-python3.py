# 116. Populating Next Right Pointers in Each Node
# Difficulty: Medium
# Status: Accepted
# Runtime: 51 ms (beats 88.6%)
# Memory: 20.7 MB (beats 49.7%)
# Submitted: 2026-04-25 07:13:41 UTC
# URL: https://leetcode.com/submissions/detail/1987526568/

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
            nextLevel = []
            for _ in range(len(q)):
                node = q.popleft()

                node.next = q[0] if len(q) > 0 else None

                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            
            q.extend(nextLevel)
        
        return root

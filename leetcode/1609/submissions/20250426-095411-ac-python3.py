# 1609. Even Odd Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 75 ms (beats 17.4%)
# Memory: 45.4 MB (beats 100.0%)
# Submitted: 2025-04-26 09:54:11 UTC
# URL: https://leetcode.com/submissions/detail/1618258156/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        def isEven(val):
            return val % 2 == 0

        q = deque([root])
        level = 0

        while q:
            n = len(q)

            prev_val = float('-inf') if isEven(level) else float('inf')
            for _ in range(n):
                node = q.popleft()

                if (
                    (isEven(level) and (isEven(node.val) or node.val <= prev_val)) or
                    (not isEven(level) and (not isEven(node.val) or node.val >= prev_val))
                ):
                    return False
                prev_val = node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                
            level += 1
        return True

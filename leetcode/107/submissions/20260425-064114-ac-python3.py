# 107. Binary Tree Level Order Traversal II
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 19.6 MB (beats 7.7%)
# Submitted: 2026-04-25 06:41:14 UTC
# URL: https://leetcode.com/submissions/detail/1987506130/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        q = deque([root])
        res = []

        while q:
            level = []

            for _ in range(len(q)):
                node = q.popleft()

                level.append(node.val)
                
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            res.append(level)
        
        res.reverse()
        return res

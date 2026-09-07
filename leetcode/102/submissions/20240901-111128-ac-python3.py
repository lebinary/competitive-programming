# 102. Binary Tree Level Order Traversal
# Difficulty: Medium
# Status: Accepted
# Runtime: 35 ms (beats 1.3%)
# Memory: 17.2 MB (beats 100.0%)
# Submitted: 2024-09-01 11:11:28 UTC
# URL: https://leetcode.com/submissions/detail/1375297093/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        res = []
        q = deque([root])

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
        
        return res
